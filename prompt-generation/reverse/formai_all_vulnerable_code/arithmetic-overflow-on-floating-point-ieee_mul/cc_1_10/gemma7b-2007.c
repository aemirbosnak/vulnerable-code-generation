//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void invade_calculator()
{
    char operator;
    float num1, num2, result;

    // Capture the operator
    printf("Enter an operator (+, -, *, /, %): ");
    scanf(" %c", &operator);

    // Capture the first number
    printf("Enter the first number: ");
    scanf(" %f", &num1);

    // Capture the second number
    printf("Enter the second number: ");
    scanf(" %f", &num2);

    // Calculate the result based on the operator
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

    // Display the result
    printf("The result is: %.2f\n", result);
}

int main()
{
    invade_calculator();

    return 0;
}