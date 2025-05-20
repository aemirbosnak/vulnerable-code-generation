//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, state = 0, number = 0, operator = 0;
    float result = 0.0f;

    printf("Enter an expression: ");

    // Get the user input
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the input
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check for numbers
        if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            number = number * 10 + buffer[i] - '0';
        }
        // Check for operators
        else if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            state = 1;
        }
        // Check for parentheses
        else if (buffer[i] == '(' || buffer[i] == ')')
        {
            // Parentheses are not implemented in this calculator
            printf("Error: Parentheses are not supported.\n");
            return 1;
        }
    }

    // Check if the user entered an operator
    if (state == 0)
    {
        printf("Error: You must enter an operator.\n");
        return 1;
    }

    // Calculate the result
    switch (operator)
    {
        case '+':
            result = (float)number + result;
            break;
        case '-':
            result = (float)number - result;
            break;
        case '*':
            result = (float)number * result;
            break;
        case '/':
            if (number == 0)
            {
                printf("Error: Cannot divide by zero.\n");
                return 1;
            }
            result = (float)number / result;
            break;
    }

    // Print the result
    printf("The result is: %.2f\n", result);

    return 0;
}