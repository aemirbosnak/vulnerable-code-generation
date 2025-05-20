//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

void main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double operand1, operand2, result;
    int i = 0;

    printf("Enter an expression: ");

    // Get the user's input
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the user's input
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check if the character is an operator
        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            break;
        }
    }

    // Get the operands
    operand1 = atof(buffer);
    operand2 = atof(buffer + i + 1);

    // Perform the operation
    switch (operator)
    {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);
}