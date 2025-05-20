//FormAI DATASET v1.0 Category: Calculator ; Style: sophisticated
#include <stdio.h>

/* Declaration of Functions */
int add(int, int);
int subtract(int, int);
int multiply(int, int);
float divide(int, int);

/* Main Function */
int main()
{
    int num1, num2, choice;
    
    /* Prompting user for input */
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    /* Displaying options to user */
    printf("\nChoose operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    /* Switch case for different options */
    switch(choice)
    {
        case 1: // Addition
            printf("Result: %d + %d = %d\n", num1, num2, add(num1, num2));
            break;
        case 2: // Subtraction
            printf("Result: %d - %d = %d\n", num1, num2, subtract(num1, num2));
            break;
        case 3: // Multiplication
            printf("Result: %d * %d = %d\n", num1, num2, multiply(num1, num2));
            break;
        case 4: // Division
            printf("Result: %d / %d = %.2f\n", num1, num2, divide(num1, num2));
            break;
        default:
            printf("Invalid choice! Please enter valid choice.\n");
    }

    return 0;
}

/* Function Definitions */
int add(int num1, int num2)
{
    return num1 + num2;
}

int subtract(int num1, int num2)
{
    return num1 - num2;
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}

float divide(int num1, int num2)
{
    return (float)num1 / num2;
}