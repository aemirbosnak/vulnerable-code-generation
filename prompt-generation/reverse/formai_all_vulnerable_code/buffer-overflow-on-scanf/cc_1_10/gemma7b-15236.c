//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator
{
    char buffer[MAX_BUFFER_SIZE];
    int top;
    char operator;
    double result;
} Calculator;

void calculator_init(Calculator *calc)
{
    calc->top = 0;
    calc->operator = '\0';
    calc->result = 0.0;
    calc->buffer[0] = '\0';
}

void calculator_add(Calculator *calc, char operator, double number)
{
    calc->operator = operator;
    calc->buffer[calc->top++] = number;
    calc->result = 0.0;
}

double calculator_calculate(Calculator *calc)
{
    switch (calc->operator)
    {
        case '+':
            calc->result = calc->buffer[0] + calc->buffer[1];
            break;
        case '-':
            calc->result = calc->buffer[0] - calc->buffer[1];
            break;
        case '*':
            calc->result = calc->buffer[0] * calc->buffer[1];
            break;
        case '/':
            if (calc->buffer[1] == 0)
            {
                printf("Error: division by zero\n");
                return -1;
            }
            calc->result = calc->buffer[0] / calc->buffer[1];
            break;
        default:
            printf("Error: invalid operator\n");
            return -1;
    }

    return calc->result;
}

int main()
{
    Calculator calc;
    calculator_init(&calc);

    char operator;
    double number;

    printf("Enter an operator (+, -, *, /, =): ");
    scanf("%c", &operator);

    if (operator == '=')
    {
        printf("Enter the result: ");
        scanf("%lf", &number);
        calculator_add(&calc, operator, number);
        double result = calculator_calculate(&calc);
        if (result != -1)
        {
            printf("The result is: %.2lf\n", result);
        }
    }
    else
    {
        printf("Enter the number: ");
        scanf("%lf", &number);
        calculator_add(&calc, operator, number);
        double result = calculator_calculate(&calc);
        if (result != -1)
        {
            printf("The result is: %.2lf\n", result);
        }
    }

    return 0;
}