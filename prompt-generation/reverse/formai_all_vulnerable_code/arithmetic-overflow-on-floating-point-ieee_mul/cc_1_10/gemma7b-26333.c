//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void calculate(char **buffer, int *index, double *result)
{
    double num1 = atof(*buffer[*index - 1]);
    double num2 = atof(*buffer[*index]);

    switch (*buffer[*index - 2])
    {
        case '+':
            *result = num1 + num2;
            break;
        case '-':
            *result = num1 - num2;
            break;
        case '*':
            *result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: Divide by zero is not allowed.\n");
                exit(1);
            }
            *result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            exit(1);
    }

    *index++;
    *buffer = realloc(*buffer, MAX_BUFFER_SIZE);
    *buffer[*index] = '\0';
}

int main()
{
    char **buffer = (char **)malloc(MAX_BUFFER_SIZE);
    int index = 0;
    double result = 0;

    printf("Enter an expression: ");

    // Get the expression from the user
    buffer[index] = malloc(1);
    buffer[index++] = getchar();

    // Calculate the result
    while (buffer[index - 1] != '\0')
    {
        calculate(buffer, &index, &result);
    }

    // Print the result
    printf("The result is: %.2lf\n", result);

    free(buffer);

    return 0;
}