//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator
{
    char buffer[MAX_BUFFER_SIZE];
    int position;
    double result;
} Calculator;

Calculator* createCalculator()
{
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->position = 0;
    calculator->result = 0.0;
    return calculator;
}

void addToBuffer(Calculator* calculator, char character)
{
    if (calculator->position >= MAX_BUFFER_SIZE - 1)
    {
        return;
    }

    calculator->buffer[calculator->position++] = character;
}

double calculate(Calculator* calculator)
{
    double number = 0.0;
    int i = 0;

    for (i = 0; calculator->buffer[i] != '\0'; i++)
    {
        switch (calculator->buffer[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                number = number * 10 + calculator->buffer[i] - '0';
                break;
            case '.':
                number = number + 0.1 * (calculator->buffer[i + 1] - '0');
                break;
            case '+':
                calculator->result += number;
                break;
            case '-':
                calculator->result -= number;
                break;
            case '*':
                calculator->result *= number;
                break;
            case '/':
                calculator->result /= number;
                break;
            case '^':
                calculator->result = pow(calculator->result, number);
                break;
            default:
                return -1;
        }
    }

    return calculator->result;
}

int main()
{
    Calculator* calculator = createCalculator();

    char input;

    printf("Enter an expression: ");
    scanf("%c", &input);

    addToBuffer(calculator, input);

    double result = calculate(calculator);

    if (result != -1)
    {
        printf("The result is: %.2lf\n", result);
    }
    else
    {
        printf("Error: invalid expression.\n");
    }

    return 0;
}