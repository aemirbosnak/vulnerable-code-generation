//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define PI constant
#define PI 3.14159

int main()
{
    double num1, num2, result;
    char operator;

    printf("Welcome to the Curious Scientific Calculator!\n");
    printf("Please enter an operator (+, -, *, /, sin, cos, tan, log): ");
    scanf("%c", &operator);

    switch(operator)
    {
        case '+':
            // Addition operation
            printf("Enter two numbers to add:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            // Subtraction operation
            printf("Enter two numbers to subtract:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            // Multiplication operation
            printf("Enter two numbers to multiply:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            // Division operation
            printf("Enter two numbers to divide:\n");
            scanf("%lf %lf", &num1, &num2);
            if(num2 == 0)
            {
                printf("Error: Division by zero.\n");
                exit(0);
            }
            else
            {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        case 's':
            // Sine operation
            printf("Enter the angle in degrees to find the sin:\n");
            scanf("%lf", &num1);
            result = sin(num1 * PI / 180);
            printf("sin(%.2lf) = %.2lf\n", num1, result);
            break;
        case 'c':
            // Cosine operation
            printf("Enter the angle in degrees to find the cos:\n");
            scanf("%lf", &num1);
            result = cos(num1 * PI / 180);
            printf("cos(%.2lf) = %.2lf\n", num1, result);
            break;
        case 't':
            // Tangent operation
            printf("Enter the angle in degrees to find the tan:\n");
            scanf("%lf", &num1);
            result = tan(num1 * PI / 180);
            printf("tan(%.2lf) = %.2lf\n", num1, result);
            break;
        case 'l':
            // Logarithm operation
            printf("Enter a number to find the natural logarithm:\n");
            scanf("%lf", &num1);
            result = log(num1);
            printf("ln(%.2lf) = %.2lf\n", num1, result);
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }

    printf("Thank you for using the Curious Scientific Calculator!\n");

    return 0;
}