//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_pos = 0;
double result = 0.0;

void clear_buffer()
{
    buffer_pos = 0;
    result = 0.0;
}

void append_number(double num)
{
    char num_str[20];
    sprintf(num_str, "%lf", num);

    if (buffer_pos >= MAX_BUFFER_SIZE - 1)
    {
        return;
    }

    buffer[buffer_pos++] = num_str[0];
    buffer[buffer_pos++] = '.';
}

void handle_operator(char operator)
{
    double operand1 = atof(buffer);

    switch (operator)
    {
        case '+':
            result = operand1 + result;
            break;
        case '-':
            result = operand1 - result;
            break;
        case '*':
            result = operand1 * result;
            break;
        case '/':
            if (operand1 == 0)
            {
                return;
            }
            result = operand1 / result;
            break;
        default:
            return;
    }

    clear_buffer();
    append_number(result);
}

int main()
{
    char input;

    printf("Enter an expression: ");

    while ((input = getchar()) != '\n')
    {
        switch (input)
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
                append_number(input - '0' + 0.0);
                break;
            case '.':
                append_number(0.0);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                handle_operator(input);
                break;
            default:
                clear_buffer();
                printf("Invalid input.\n");
                break;
        }
    }

    printf("The result is: %lf\n", result);

    return 0;
}