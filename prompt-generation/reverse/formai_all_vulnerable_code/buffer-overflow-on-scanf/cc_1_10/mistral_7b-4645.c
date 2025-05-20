//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: curious
// ***************************************************************************************
// * FACTORIAL FUNCTION WITH A DASH OF CURIOSITY                                            *
// *                                                                                       *
// * This program calculates the factorial of a given number using a recursive function      *
// * named "The Great Divider" and "The Multiplier of Miracles".                           *
// *                                                                                       *
// * The Great Divider is responsible for dividing the number by each natural number        *
// * less than it until it reaches 1.                                                       *
// * The Multiplier of Miracles, on the other hand, takes the product of all numbers         *
// * between 1 and the number given to it.                                                  *
// *                                                                                       *
// * To make things even more curious, the function prints a message for each division and   *
// * multiplication operation, along with some amusing comments.                            *
// *                                                                                       *
// * Note: This program is not optimized for large numbers, as recursion is not the best   *
// * solution for large factorials.                                                         *
// *                                                                                       *
// ***************************************************************************************

#include <stdio.h>
#include <stdlib.h>

// ***************************************************************************************
// * The Great Divider: A curious name for a function that divides a number              *
// * by each natural number less than it.                                               *
// ***************************************************************************************
int The_Great_Divider(int number, int divisor);

// ***************************************************************************************
// * The Multiplier of Miracles: A curious name for a function that takes the product    *
// * of all numbers between 1 and the given number.                                      *
// ***************************************************************************************
int The_Multiplier_of_Miracles(int number);

// ***************************************************************************************
// * Calculates the factorial of a given number using recursion and some curiosity.       *
// ***************************************************************************************
int Factorial_Fun(int number) {
    if (number == 0) {
        return 1;
    }

    int product = The_Multiplier_of_Miracles(number);
    int quotient = number;

    printf("\nThe Great Divider is now dividing %d by %d...\n", number, quotient);
    quotient = The_Great_Divider(number, quotient);

    printf("The result is %d! So The Multiplier of Miracles will now take the product of %d and %d...\n", quotient, number, product);
    product *= number;

    return product;
}

// ***************************************************************************************
// * Divides the given number by the divisor.                                            *
// ***************************************************************************************
int The_Great_Divider(int number, int divisor) {
    int quotient;

    quotient = number / divisor;
    return quotient;
}

// ***************************************************************************************
// * Takes the product of all numbers between 1 and the given number.                      *
// ***************************************************************************************
int The_Multiplier_of_Miracles(int number) {
    int product = 1;
    int i;

    for (i = 1; i <= number; i++) {
        product *= i;
    }

    return product;
}

// ***************************************************************************************
// * Main function: Calculate and print the factorial of a given number.                *
// ***************************************************************************************
int main() {
    int number;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);

    printf("The factorial of %d is: %d\n", number, Factorial_Fun(number));

    return 0;
}