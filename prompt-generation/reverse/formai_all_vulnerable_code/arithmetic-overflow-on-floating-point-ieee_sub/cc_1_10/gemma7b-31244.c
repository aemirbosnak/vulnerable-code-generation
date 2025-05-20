//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare variables
double num1, num2, result;
char operator;

// Function to perform calculations
void calculate()
{
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Cannot divide by zero\n");
            }
            else
            {
                result = num1 / num2;
            }
            break;
        default:
            printf("Invalid operator\n");
    }
}

int main()
{
    // Get the first number
    printf("Enter the first number: ");
    scanf("%lf", &num1);

    // Get the operator
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    // Perform the calculations
    calculate();

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}