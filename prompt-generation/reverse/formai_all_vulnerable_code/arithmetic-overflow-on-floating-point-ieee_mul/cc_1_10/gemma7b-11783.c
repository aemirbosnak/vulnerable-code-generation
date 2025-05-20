//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the calculator function
void calculator()
{
    // Get the first number from the user
    float num1;
    printf("Enter the first number: ");
    scanf("%f", &num1);

    // Get the operator from the user
    char operator;
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Get the second number from the user
    float num2;
    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Perform the calculation
    float result;
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
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }

    // Print the result
    printf("The result is: %.2f\n", result);
}

int main()
{
    // Calculate the value
    calculator();

    return 0;
}