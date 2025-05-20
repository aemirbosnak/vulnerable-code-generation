//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator
{
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
} Calculator;

Calculator calculator;

void initCalculator()
{
    calculator.pos = 0;
    calculator.historyPos = 0;
    calculator.history[0] = 0;
}

void addToBuffer(char c)
{
    if (calculator.pos >= MAX_BUFFER_SIZE - 1)
    {
        return;
    }

    calculator.buffer[calculator.pos++] = c;
}

void clearBuffer()
{
    calculator.pos = 0;
}

void calculate()
{
    char operator = calculator.buffer[calculator.pos - 1];
    int operand1 = atoi(calculator.buffer);
    int operand2 = atoi(calculator.buffer + calculator.pos);

    switch (operator)
    {
        case '+':
            calculator.history[calculator.historyPos++] = operand1 + operand2;
            break;
        case '-':
            calculator.history[calculator.historyPos++] = operand1 - operand2;
            break;
        case '*':
            calculator.history[calculator.historyPos++] = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0)
            {
                return;
            }
            calculator.history[calculator.historyPos++] = operand1 / operand2;
            break;
    }

    clearBuffer();
}

int main()
{
    initCalculator();

    char input;
    printf("Enter an expression: ");

    while ((input = getchar()) != '\n')
    {
        addToBuffer(input);
    }

    calculate();

    printf("History: ");

    for (int i = 0; i < calculator.historyPos; i++)
    {
        printf("%d ", calculator.history[i]);
    }

    printf("\n");

    return 0;
}