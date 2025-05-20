//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void solveCase(char** argv)
{
    char operator;
    float num1, num2, result;

    printf("Good evening, Mr. Holmes. You have a case for me this evening.\n");

    printf("Please provide me with the operator you want to use (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Please provide me with the first number: ");
    scanf("%f", &num1);

    printf("Please provide me with the second number: ");
    scanf("%f", &num2);

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
                printf("Error: cannot divide by zero.\n");
            }
            else
            {
                result = num1 / num2;
            }
            break;
        default:
            printf("Error: invalid operator.\n");
    }

    if (result != 0)
    {
        printf("The result is: %.2f\n", result);
    }
    else
    {
        printf("No result.\n");
    }

    printf("Thank you for letting me help you, Mr. Holmes.\n");
}

int main()
{
    solveCase(NULL);

    return 0;
}