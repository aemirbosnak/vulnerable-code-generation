//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char op;
    float num1, num2, result;
    int i, flag = 0;

    printf("Enter an operator (+, -, *, /, %): ");
    op = getchar();

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

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

    if (flag == 0)
    {
        printf("The result is: %.2f\n", result);
    }

    return 0;
}