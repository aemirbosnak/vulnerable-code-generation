//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void clear_buffer(char *);

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, num1, num2, operator, result;
    char ch;

    printf("Enter an expression: ");

    // Get the expression from the user
    gets(buffer);

    // Loop over the expression to identify the operator and operands
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Check if the character is an operator
        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            num1 = atoi(&buffer[i - 1]);
            num2 = atoi(&buffer[i + 1]);
            break;
        }
    }

    // Perform the calculation
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
                printf("Error: division by zero is not allowed.\n");
            }
            else
            {
                result = num1 / num2;
            }
            break;
    }

    // Display the result
    printf("The result is: %d\n", result);

    return 0;
}

void clear_buffer(char *buffer)
{
    int i;

    for (i = 0; buffer[i] != '\0'; i++)
    {
        buffer[i] = '\0';
    }
}