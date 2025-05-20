//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
int getIntegerInput(void);
bool isPrimeNumber(int);
int calculateGcd(int, int);

int main()
{
    int integerOne, integerTwo; // declare two integers for input

    printf("Welcome to the Arithmetic program!\n");

    // get the first integer input and check if it is a prime number
    printf("Enter the first integer: ");
    integerOne = getIntegerInput();
    if (isPrimeNumber(integerOne))
    {
        printf("%d is a prime number!\n", integerOne);
    }
    else
    {
        printf("%d is not a prime number.\n", integerOne);
    }

    // get the second integer input and calculate the GCD
    printf("Enter the second integer: ");
    integerTwo = getIntegerInput();
    printf("The GCD of %d and %d is %d.\n", integerOne, integerTwo, calculateGcd(integerOne, integerTwo));

    printf("Thank you for using the Arithmetic program!\n");

    return 0;
}

/**
 * Function: getIntegerInput
 * ------------------------
 * Prompts the user to enter an integer input and returns the validated integer.
 *
 * returns: integer input by user
 */
int getIntegerInput(void)
{
    char userInput[10]; // array to hold the user input
    int integerInput; // integer to be returned

    while (true)
    {
        // get the user input as a string
        fgets(userInput, sizeof(userInput), stdin);

        // convert the input string to an integer
        if (sscanf(userInput, "%d", &integerInput) == 1)
        {
            break; // input is valid, exit the loop
        }

        printf("Invalid input. Please enter an integer: ");
    }

    return integerInput;
}

/**
 * Function: isPrimeNumber
 * -----------------------
 * Checks if a given number is a prime number.
 *
 * num: number to be checked
 * returns: true if num is a prime number, false otherwise
 */
bool isPrimeNumber(int num)
{
    if (num < 2)
    {
        return false; // primes start from 2 and above
    }

    int i;
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return false; // found a factor of num
        }
    }

    return true; // num has no factors other than 1 and itself
}

/**
 * Function: calculateGcd
 * ----------------------
 * Calculates the Greatest Common Divisor (GCD) of two numbers using the Euclidean Algorithm.
 *
 * num1: the first number
 * num2: the second number
 * returns: the GCD of num1 and num2
 */
int calculateGcd(int num1, int num2)
{
    int remainder;

    while (num2)
    {
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }

    return num1;
}