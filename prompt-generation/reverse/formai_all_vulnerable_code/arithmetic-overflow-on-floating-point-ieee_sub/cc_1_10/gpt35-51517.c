//FormAI DATASET v1.0 Category: Calculator ; Style: introspective
#include<stdio.h>

int main()
{
    // Declare variables to hold user input
    float num1, num2;
    int choice;

    // Display menu to user
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                                 Calculator\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("Choose an operation from the options below:\n\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n\n");

    // Get user input
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Check if user input is valid
    if(choice < 1 || choice > 4)
    {
        printf("Invalid choice. Please enter a valid choice (1-4).\n");
        return 0;
    }

    // Get user input for numbers
    printf("\nEnter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    // Declare variables for calculations
    float result;
    char operator;

    // Perform calculations and display results based on user choice
    switch(choice)
    {
        case 1:
            result = num1 + num2;
            operator = '+';
            break;

        case 2:
            result = num1 - num2;
            operator = '-';
            break;

        case 3:
            result = num1 * num2;
            operator = '*';
            break;

        case 4:
            // Check if second number is zero, because division by zero is undefined
            if(num2 == 0)
            {
                printf("Undefined\n");
                return 0;
            }
            result = num1 / num2;
            operator = '/';
            break;
    }

    // Display results to user
    printf("\nResult: %.2f %c %.2f = %.2f\n", num1, operator, num2, result);

    return 0;
}