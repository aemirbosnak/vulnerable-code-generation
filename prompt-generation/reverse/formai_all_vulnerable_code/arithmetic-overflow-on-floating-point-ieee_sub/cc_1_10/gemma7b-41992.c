//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    char operator;
    float num1, num2, result;
    int i, flag = 0;

    // Allocate memory for the calculator's history
    char *history = (char *)malloc(MAX_SIZE);

    // Get the operator and two numbers
    printf("Enter an operator (+, -, *, /, %): ");
    operator = getchar();

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Calculate the result
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Cannot divide by zero\n");
                flag = 1;
            }
            else
            {
                result = num1 / num2;
            }
            break;
        default:
            printf("Invalid operator\n");
            flag = 1;
    }

    // Store the history
    if (!flag)
    {
        history[i] = operator;
        history[i+1] = num1;
        history[i+2] = num2;
        history[i+3] = result;
        i++;
    }

    // Display the result
    if (!flag)
    {
        printf("The result is: %.2f\n", result);
    }

    // Free the allocated memory
    free(history);

    return 0;
}