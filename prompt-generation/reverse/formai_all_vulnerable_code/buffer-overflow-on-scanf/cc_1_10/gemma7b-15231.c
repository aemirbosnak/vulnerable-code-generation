//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_position = 0;
int buffer_size = 0;

void add_to_buffer(char character)
{
    if (buffer_size == buffer_position)
    {
        buffer_position = 0;
        buffer_size = 0;
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    buffer[buffer_position++] = character;
    buffer_size++;
}

int main()
{
    char operator;
    char number1, number2;
    int result;

    printf("Enter an operator (+, -, *, /, %): ");
    scanf("%c", &operator);

    printf("Enter the first number: ");
    scanf("%c", &number1);

    printf("Enter the second number: ");
    scanf("%c", &number2);

    switch (operator)
    {
        case '+':
            result = number1 - number2;
            break;
        case '-':
            result = number1 + number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            result = number1 / number2;
            break;
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    printf("The result is: %d\n", result);

    return 0;
}