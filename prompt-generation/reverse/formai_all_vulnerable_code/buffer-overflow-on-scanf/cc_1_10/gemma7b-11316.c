//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;

void add_to_buffer(char character)
{
    if (buffer_position >= MAX_BUFFER_SIZE - 1)
    {
        return;
    }

    buffer[buffer_position++] = character;
}

void clear_buffer()
{
    buffer_position = 0;
}

double calculate_expression()
{
    char operator = '\0';
    double number1 = 0.0;
    double number2 = 0.0;

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (isdigit(buffer[i]))
        {
            number1 = number1 * 10 + buffer[i] - '0';
        }
        else if (operator == '\0')
        {
            operator = buffer[i];
        }
        else
        {
            number2 = number2 * 10 + buffer[i] - '0';
            double result = 0.0;

            switch (operator)
            {
                case '+':
                    result = number1 + number2;
                    break;
                case '-':
                    result = number1 - number2;
                    break;
                case '*':
                    result = number1 * number2;
                    break;
                case '/':
                    if (number2 == 0)
                    {
                        return -1;
                    }
                    result = number1 / number2;
                    break;
                default:
                    return -1;
            }

            clear_buffer();
            add_to_buffer(result);
            number1 = result;
        }
    }

    return number1;
}

int main()
{
    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    clear_buffer();
    for (int i = 0; input[i] != '\0'; i++)
    {
        add_to_buffer(input[i]);
    }

    double result = calculate_expression();

    if (result == -1)
    {
        printf("Error!\n");
    }
    else
    {
        printf("The result is: %.2lf\n", result);
    }

    return 0;
}