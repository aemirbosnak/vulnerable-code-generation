//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void clear_buffer(char *);

int main()
{
    char buffer[MAX_BUFFER_SIZE] = "";
    char operator;
    float number1, number2, result;

    printf("Welcome to the Funky Scientific Calculator!\n");

    printf("Enter an operator (+, -, *, /, %): ");
    operator = getchar();

    printf("Enter the first number: ");
    scanf("%f", &number1);

    printf("Enter the second number: ");
    scanf("%f", &number2);

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
                printf("Cannot divide by zero!\n");
            }
            else
            {
                result = number1 / number2;
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    if (result != 0)
    {
        printf("The result is: %.2f\n", result);
    }

    clear_buffer(buffer);

    return 0;
}

void clear_buffer(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0')
    {
        buffer[i] = '\0';
        i++;
    }
}