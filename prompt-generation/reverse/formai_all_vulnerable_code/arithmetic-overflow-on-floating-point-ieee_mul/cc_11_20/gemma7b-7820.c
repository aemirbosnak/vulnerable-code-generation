//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    char op;
    float num1, num2, result;
    int i, flag = 0;

    // Display calculator menu
    printf("Enter an operator (+, -, *, /, %): ");

    // Get operator
    op = getchar();

    // Validate operator
    switch (op)
    {
        case '+':
            flag = 1;
            break;
        case '-':
            flag = 1;
            break;
        case '*':
            flag = 1;
            break;
        case '/':
            flag = 1;
            break;
        default:
            printf("Invalid operator.\n");
            return 0;
    }

    // Get first number
    printf("Enter the first number: ");
    scanf("%f", &num1);

    // Get second number
    printf("Enter the second number: ");
    scanf("%f", &num2);

    // Calculate result
    switch (op)
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
                printf("Cannot divide by zero.\n");
                return 0;
            }
            result = num1 / num2;
            break;
    }

    // Display result
    printf("The result is: %.2f\n", result);

    // Flag check
    if (flag == 0)
    {
        printf("Invalid input.\n");
    }

    return 0;
}