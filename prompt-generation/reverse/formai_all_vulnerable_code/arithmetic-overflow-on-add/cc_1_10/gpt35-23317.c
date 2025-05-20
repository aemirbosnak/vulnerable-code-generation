//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include<stdio.h>

/**
 * This program takes in two numbers as input from the user and performs arithmetic operations on them.
 * The program also demonstrates the use of conditional statements and looping constructs.
 */

int main()
{
    int num1, num2; //declaring integer variables to store the user input
    int choice; //declaring a variable to store the user's choice of operation
    int result; //declaring a variable to store the result of the arithmetic operation
    int i; //declaring a variable to be used as a counter in the for loop

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nChoose an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            result = num1 + num2;
            printf("\n%d + %d = %d\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\n%d - %d = %d\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\n%d * %d = %d\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0)
            {
                printf("\nDivision by zero is undefined. Please enter a non-zero number for the second operand.\n");
            }
            else
            {
                result = num1 / num2;
                printf("\n%d / %d = %d\n", num1, num2, result);
            }
            break;
        default:
            printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
    }

    printf("\nHere are the first twenty multiples of the result:\n");

    for(i = 1; i <= 20; i++)
    {
        printf("%d x %d = %d\n", result, i, result*i);
    }

    return 0;
}