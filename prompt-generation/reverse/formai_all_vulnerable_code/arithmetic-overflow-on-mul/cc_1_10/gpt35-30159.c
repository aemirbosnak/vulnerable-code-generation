//FormAI DATASET v1.0 Category: Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to add two numbers
int addition(int num1, int num2)
{
    return num1 + num2;
}

// Function to subtract two numbers
int subtraction(int num1, int num2)
{
    return num1 - num2;
}

// Function to multiply two numbers
int multiplication(int num1, int num2)
{
    return num1 * num2;
}

// Function to divide two numbers
float division(int num1, int num2)
{
    if(num2 == 0)
    {
        printf("Cannot divide by zero");
        exit(0);
    }
    return (float) num1 / num2;
}


int main()
{
    int num1, num2, choice, result;
    char ch;

    printf("Welcome to the Calculator Program\n");

    do{
        printf("\nEnter two numbers: ");
        scanf("%d %d", &num1, &num2);

        printf("Please choose from the following options:\n");
        printf("1: Addition\n");
        printf("2: Subtraction\n");
        printf("3: Multiplication\n");
        printf("4: Division\n");
        printf("5: Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: // Addition
                result = addition(num1, num2);
                printf("The result of %d + %d is %d\n", num1, num2, result);
                break;

            case 2: // Subtraction
                result = subtraction(num1, num2);
                printf("The result of %d - %d is %d\n", num1, num2, result);
                break;

            case 3: // Multiplication
                result = multiplication(num1, num2);
                printf("The result of %d * %d is %d\n", num1, num2, result);
                break;

            case 4: // Division
                printf("The result of %d / %d is %.2f\n", num1, num2, division(num1, num2));
                break;

            case 5: // Exit
                printf("Thank you for using the calculator program. Goodbye!");
                exit(0);

            default: // Invalid input
                printf("Invalid choice. Please enter a valid choice.");
                break;
        }

        // Ask the user if they want to continue
        printf("\nDo you want to continue? (y/n) ");
        scanf(" %c", &ch);

    }while(ch == 'y' || ch == 'Y');

    printf("Thank you for using the calculator program. Goodbye!");

    return 0;
}