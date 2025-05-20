//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float num1, num2, result; // Declare three variables for number inputs and result

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("We will be performing a series of calculations using C Math library functions\n");
    printf("Let's get started!\n\n");

    // Get user input for the first number
    printf("What is the first number? ");
    scanf("%f", &num1);

    // Get user input for the second number
    printf("What is the second number? ");
    scanf("%f", &num2);

    // Calculation 1: Addition
    result = num1 + num2;
    printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);

    // Calculation 2: Subtraction
    result = num1 - num2;
    printf("%.2f - %.2f = %.2f\n", num1, num2, result);

    // Calculation 3: Multiplication
    result = num1 * num2;
    printf("%.2f * %.2f = %.2f\n", num1, num2, result);

    // Calculation 4: Division
    if (num2 != 0) // Check for division by zero
    {
        result = num1 / num2;
        printf("%.2f / %.2f = %.2f\n", num1, num2, result);
    }
    else
    {
        printf("Division by zero is not allowed.\n");
    }

    // Calculation 5: Square Root
    if (num1 >= 0) // Check for negative number
    {
        result = sqrt(num1);
        printf("The square root of %.2f is %.2f\n", num1, result);
    }
    else
    {
        printf("Square root of negative numbers is not defined.\n");
    }
    
    // Calculation 6: Trigonometric functions
    result = sin(num2);
    printf("The sine of %.2f is %.2f\n", num2, result);
    
    result = cos(num2);
    printf("The cosine of %.2f is %.2f\n", num2, result);
    
    result = tan(num2);
    printf("The tangent of %.2f is %.2f\n", num2, result);

    printf("\nThank you for using the Math Exercise Program! Goodbye!\n");

    return 0;
}