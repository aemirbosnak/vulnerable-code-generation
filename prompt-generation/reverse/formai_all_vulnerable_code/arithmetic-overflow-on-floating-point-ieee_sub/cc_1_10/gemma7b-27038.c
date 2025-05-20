//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    char operator;
    double number1, number2;

    printf("Enter an expression: ");
    while (1)
    {
        char character = getchar();
        if (character == '\n')
        {
            break;
        }
        else if (character == ' ')
        {
            buffer[i] = '\0';
            i = 0;
        }
        else
        {
            buffer[i] = character;
            i++;
        }
    }

    operator = buffer[i - 1];
    number1 = atof(buffer);
    number2 = atof(buffer + i);

    switch (operator)
    {
        case '+':
            printf("The result is: %.2lf", number1 + number2);
            break;
        case '-':
            printf("The result is: %.2lf", number1 - number2);
            break;
        case '*':
            printf("The result is: %.2lf", number1 * number2);
            break;
        case '/':
            if (number2 == 0)
            {
                printf("Error: division by zero is not allowed");
            }
            else
            {
                printf("The result is: %.2lf", number1 / number2);
            }
            break;
        default:
            printf("Invalid operator");
    }

    printf("\n");
}