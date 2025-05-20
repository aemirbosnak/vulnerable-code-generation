//FormAI DATASET v1.0 Category: Calculator ; Style: creative
// This is a unique C calculator program that creatively calculates basic arithmetic operations

#include<stdio.h>

int sum(int a, int b); // Function to add two numbers
int difference(int a, int b); // Function to find the difference between two numbers
int product(int a, int b); // Function to multiply two numbers
int quotient(int a, int b); // Function to divide two numbers
void display(int result); // Function to display the result

int main()
{
    int choice, num1, num2, result;
    printf("Welcome to the Creative C Calculator Program\n\n");

    do
    {
        printf("Choose an option from the following:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%d%d", &num1, &num2);
                result = sum(num1, num2);
                display(result);
                break;

            case 2:
                printf("Enter two numbers to find the difference: ");
                scanf("%d%d", &num1, &num2);
                result = difference(num1, num2);
                display(result);
                break;

            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%d%d", &num1, &num2);
                result = product(num1, num2);
                display(result);
                break;

            case 4:
                printf("Enter the dividend and divisor: ");
                scanf("%d%d", &num1, &num2);
                result = quotient(num1, num2);
                display(result);
                break;

            case 5:
                printf("Thank you for using the Creative C Calculator Program!");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n\n");
        }

    } while(choice != 5);

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}

int difference(int a, int b)
{
    return a - b;
}

int product(int a, int b)
{
    return a * b;
}

int quotient(int a, int b)
{
    if(b == 0)
    {
        printf("Error! Division by zero\n");
        return 0;
    }
    else
    {
        return a / b;
    }
}

void display(int result)
{
    printf("The result is: %d\n\n", result);
}