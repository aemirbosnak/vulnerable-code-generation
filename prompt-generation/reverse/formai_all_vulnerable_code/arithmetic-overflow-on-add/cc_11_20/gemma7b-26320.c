//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, stack[MAX_BUFFER_SIZE], top = -1;
    char operator, operand;
    double result;

    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            operand = buffer[i];
            stack[++top] = operand - 'a' + 1;
        }
        else if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            operand = buffer[i];
            stack[++top] = operand - '0';
        }
        else if (buffer[i] == '+')
        {
            operator = '+';
            j = top - 1;
            result = stack[j] + stack[top];
            stack[top] = result;
            top--;
        }
        else if (buffer[i] == '-')
        {
            operator = '-';
            j = top - 1;
            result = stack[j] - stack[top];
            stack[top] = result;
            top--;
        }
        else if (buffer[i] == '*')
        {
            operator = '*';
            j = top - 1;
            result = stack[j] * stack[top];
            stack[top] = result;
            top--;
        }
        else if (buffer[i] == '/')
        {
            operator = '/';
            j = top - 1;
            result = stack[j] / stack[top];
            stack[top] = result;
            top--;
        }
    }

    if (top != -1)
    {
        printf("Error: invalid expression\n");
    }
    else
    {
        printf("The result is: %.2lf\n", stack[0]);
    }

    return 0;
}