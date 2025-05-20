//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

char buffer[MAX_BUFFER_SIZE];
char* ptr = buffer;
int history_size = 0;
char** history = NULL;

void add_history(char* str)
{
    history_size++;
    history = realloc(history, history_size * sizeof(char*));
    history[history_size - 1] = str;
}

void clear_buffer()
{
    ptr = buffer;
    *ptr = '\0';
}

void print_history()
{
    for (int i = 0; i < history_size; i++)
    {
        printf("%s\n", history[i]);
    }
}

int main()
{
    char input[MAX_BUFFER_SIZE];
    char operator;
    float number1, number2;
    float result;

    while (1)
    {
        printf("Enter an expression: ");
        scanf("%s", input);

        operator = input[0];
        number1 = atof(input + 1);

        switch (operator)
        {
            case '+':
                clear_buffer();
                add_history(input);
                printf("Enter the second number: ");
                scanf("%f", &number2);
                result = number1 + number2;
                printf("The result is: %.2f\n", result);
                break;
            case '-':
                clear_buffer();
                add_history(input);
                printf("Enter the second number: ");
                scanf("%f", &number2);
                result = number1 - number2;
                printf("The result is: %.2f\n", result);
                break;
            case '*':
                clear_buffer();
                add_history(input);
                printf("Enter the second number: ");
                scanf("%f", &number2);
                result = number1 * number2;
                printf("The result is: %.2f\n", result);
                break;
            case '/':
                clear_buffer();
                add_history(input);
                printf("Enter the second number: ");
                scanf("%f", &number2);
                result = number1 / number2;
                printf("The result is: %.2f\n", result);
                break;
            case 'h':
                print_history();
                break;
            default:
                printf("Invalid operator.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}