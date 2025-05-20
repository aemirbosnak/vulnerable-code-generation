//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: retro
// A retro-themed arithmetic example program in C

#include <stdio.h>

int main()
{
    // Initialize the variables
    int num1, num2, result;

    // Prompt the user to enter the first number
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Prompt the user to enter the second number
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Perform the addition operation
    result = num1 + num2;

    // Print the result
    printf("The sum of %d and %d is %d\n", num1, num2, result);

    // Perform the subtraction operation
    result = num1 - num2;

    // Print the result
    printf("The difference between %d and %d is %d\n", num1, num2, result);

    // Perform the multiplication operation
    result = num1 * num2;

    // Print the result
    printf("The product of %d and %d is %d\n", num1, num2, result);

    // Perform the division operation
    result = num1 / num2;

    // Print the result
    printf("The quotient of %d divided by %d is %d\n", num1, num2, result);

    // Perform the modulus operation
    result = num1 % num2;

    // Print the result
    printf("The remainder of %d divided by %d is %d\n", num1, num2, result);

    // Return 0 to indicate successful execution of the program
    return 0;
}