//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, sin, cos, tan, sqrt): ");
    scanf("%c", &operator);

    if (operator == '+' || operator == '-' || operator == '*' || operator == '/')
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &num1, &num2);

        switch(operator)
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
                result = num1 / num2;
                break;
            default:
                printf("Invalid operator.\n");
                exit(1);
        }

        printf("Result: %lf %c %lf = %lf", num1, operator, num2, result);
    }
    else if (operator == 's' || operator == 'c' || operator == 't' || operator == 'q')
    {
        printf("Enter the operand: ");
        scanf("%lf", &num1);

        switch(operator)
        {
            case 's':
                result = sin(num1);
                break;
            case 'c':
                result = cos(num1);
                break;
            case 't':
                result = tan(num1);
                break;
            case 'q':
                result = sqrt(num1);
                break;
            default:
                printf("Invalid operator.\n");
                exit(1);
        }

        printf("Result: %c(%lf) = %lf", operator, num1, result);
    }
    else
    {
        printf("Invalid operator.\n");
    }

    return 0;
}