//Stephen Stengel <stephen.stengel@cwu.edu>
//30 October 2019
//Program to test my russian peasant algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_TEST_NUM 46340

int rp(int n, int m);
int rpBit(int n, int m);
_Bool isCorrectOutput(int output, int n, int m);
int testFunction();


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Wrong number of inputs!\n");

		return 1;
	}

	printf("size of int: %lu\n", sizeof(int) );
	printf("INT_MAX: %d\n", INT_MAX);

	int intn = atoi(argv[1]);
	int intm = atoi(argv[2]);

	printf("Russian Peasant Test!\n");
	printf("Testing n = %d, m = %d\n", intn, intm);

	int output = rp(intn, intm);

	printf("The output was: %d\n", output);

	printf("This output is ");
	if ( isCorrectOutput(output, intn, intm) )
	{
		printf("correct!\n");
	}
	else
	{
		printf("WRONG!\n");
	}

	printf("\n\nNow the bit shift version!\n");
	printf("The bitShift version output was: %d\n", rpBit(intn, intm));

	printf("\n\nNow for a series of tests.\n");

	if ( testFunction() )
	{
		printf("Test passed!\n");

		return 0;
	}
	else
	{
		printf("Test FAILED!\n");

		return -1;
	}
}


//Russian Peasant algorithm using integer division.
int rp(int n, int m)
{
	int mTemp = 0;
	while (n > 1)
	{
		if (n % 2 == 1)
		{
			mTemp += m;
		}

		n = n / 2;
		m = m * 2;
	}

	return m + mTemp;
}


//Russian Peasant Algorithm using bit shifting
//Compiler probably converts division into shifting automatically so useless.
int rpBit(int n, int m)
{
	int mTemp = 0;
	while (n > 1)
	{
		if (n % 2 == 1)
		{
			mTemp += m;
		}

		n = n >> 1;
		m = m << 1;
	}

	return m + mTemp;
}


//Checks if the output number is correct.
_Bool isCorrectOutput(int output, int n, int m)
{
	if (output == (n * m))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


//My testing function.
int testFunction()
{
	_Bool noErrors = TRUE;

	//can go up to 46340 n and m on my computer before rollover.
	int n = 1;
	int m = 1;
	for ( ; (n <= MAX_TEST_NUM) && noErrors; n++)
	{
		for ( ; (m <= MAX_TEST_NUM) && noErrors; m++)
		{
			noErrors = isCorrectOutput( rp(n, m), n, m);
		}
	}

	if (noErrors)
	{
		printf("No errors found!\n");
		//printf("final n: %d\tfinal m: %d\n", n, m);
	}
	else printf("Error found for n: %d and m: %d!\n", n, m);

	return noErrors;
}
