//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;
char operator_stack[MAX_BUFFER_SIZE];
int operator_stack_position = -1;

void push_operator(char operator)
{
    if (operator_stack_position == MAX_BUFFER_SIZE - 1)
    {
        printf("Error: Operator stack overflow.\n");
        return;
    }

    operator_stack[++operator_stack_position] = operator;
}

void pop_operator()
{
    if (operator_stack_position == -1)
    {
        printf("Error: Operator stack underflow.\n");
        return;
    }

    operator_stack_position--;
}

void calculate()
{
    char operator = operator_stack[operator_stack_position];
    double num1 = atof(buffer);
    double num2 = atof(buffer + buffer_position);

    switch (operator)
    {
        case '+':
            printf("%f + %f = %f\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%f - %f = %f\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%f * %f = %f\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: Division by zero.\n");
                return;
            }
            printf("%f / %f = %f\n", num1, num2, num1 / num2);
            break;
        default:
            printf("Error: Invalid operator.\n");
            return;
    }

    buffer_position = 0;
}

int main()
{
    printf("Enter an expression: ");

    // Get the input expression from the user.
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Remove the newline character from the end of the input.
    buffer[strcspn(buffer, "\n")] = '\0';

    // Calculate the expression.
    calculate();

    return 0;
}