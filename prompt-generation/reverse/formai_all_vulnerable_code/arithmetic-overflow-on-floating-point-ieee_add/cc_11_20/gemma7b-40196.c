//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char operator;
    float number1, number2, result;

    // Loop to get the input until the user enters an operator
    while (1)
    {
        printf("Enter an operator (+, -, *, /, %): ");
        scanf("%c", &operator);

        // Check if the operator is valid
        if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
        {
            break;
        }

        printf("Invalid operator.\n");
    }

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%f", &number1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%f", &number2);

    // Perform the calculation based on the operator
    switch (operator)
    {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            if (number2 == 0)
            {
                printf("Cannot divide by zero.\n");
            }
            else
            {
                result = number1 / number2;
            }
            break;
        default:
            printf("Invalid operator.\n");
            break;
    }

    // Display the result
    printf("The result is: %.2f\n", result);

    return 0;
}