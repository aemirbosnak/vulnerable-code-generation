//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char operator = '\0';
    double result = 0.0;
    double number = 0.0;

    printf("Enter an expression: ");

    // Loop to read the expression character by character
    while (buffer[i] = getchar() != '\n')
    {
        buffer[i++] = getchar();
    }

    // Identify the operator
    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operator = buffer[i];
            break;
        }
    }

    // Convert the remaining part of the expression to a number
    number = atof(buffer);

    // Calculate the result
    switch (operator)
    {
        case '+':
            result = number + result;
            break;
        case '-':
            result = number - result;
            break;
        case '*':
            result = number * result;
            break;
        case '/':
            if (number == 0)
            {
                printf("Error: division by zero is not allowed.\n");
            }
            else
            {
                result = number / result;
            }
            break;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}