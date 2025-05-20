//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    printf("\n\n  Welcome to the Cyberpunk Scientific Calculator\n");
    printf("--------------------------------\n\n");

    char op;
    float num1, num2, result;
    int flag = 0;
  
    while (1)
    {
        // Exit condition
        if (flag)
            break;

        printf("Enter first number: ");
        scanf("%f", &num1);

        printf("Enter operation: ");
        scanf(" %c", &op);

        while (!strchr("+-*/^scqrt", op))
        {
            printf("Invalid operation. Please try again.\n");
            printf("Enter operation: ");
            scanf(" %c", &op);
        }

        // Quit calculation and exit
        if (op == 'q')
        {
            flag = 1;
            continue;
        }

        if (op != 's' && op != 'c')
        {
            printf("Enter second number: ");
            scanf("%f", &num2);
        }

        switch (op)
        {
            case '+':
                result = num1 + num2;
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case '-':
                result = num1 - num2;
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case '*':
                result = num1 * num2;
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case '/':
                if (num2 == 0)
                {
                    printf("Cannot divide by zero.\n");
                    break;
                }

                result = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                break;

            case '^':
                result = pow(num1, num2);
                printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
                break;

            case 's':
                result = sin(num1);
                printf("sin(%.2f) = %.2f\n", num1, result);
                break;

            case 'c':
                result = cos(num1);
                printf("cos(%.2f) = %.2f\n", num1, result);
                break;

            case 'q':
                flag = 1;
                continue;

            case 'r':
                result = sqrt(num1);
                printf("sqrt(%.2f) = %.2f\n", num1, result);
                break;
        }
    }

    printf("\n\nThank you for using the Cyberpunk Scientific Calculator.\n");
    return 0;
}