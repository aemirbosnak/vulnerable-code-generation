//FormAI DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>

// Function to add two integers
int add(int a, int b)
{
    return a + b;
}

// Function to subtract two integers
int subtract(int a, int b)
{
    return a - b;
}

// Function to multiply two integers
int multiply(int a, int b)
{
    return a * b;
}

// Function to divide two integers
int divide(int a, int b)
{
    return a / b;
}

int main()
{
    int x, y;
    char op;

    // Prompt user to enter two integers and an operator
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    // Switch statement to perform desired operation based on user input
    switch(op)
    {
        case '+':
            printf("%d + %d = %d\n", x, y, add(x, y));
            break;
        case '-':
            printf("%d - %d = %d\n", x, y, subtract(x, y));
            break;
        case '*':
            printf("%d * %d = %d\n", x, y, multiply(x, y));
            break;
        case '/':
            // Check if dividing by zero
            if (y == 0)
            {
                printf("Error: cannot divide by zero.\n");
            }
            else
            {
                printf("%d / %d = %d\n", x, y, divide(x, y));
            }
            break;
        default:
            printf("Error: invalid operator entered.\n");
            break;
    }

    return 0;
}