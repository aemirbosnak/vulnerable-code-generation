//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Enter an operator (+, -, *, /, sin, cos, tan, log, sqrt): ");
    scanf("%c", &operator);

    switch(operator) {
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            if(num2 != 0) {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            } else {
                printf("Error: cannot divide by zero");
            }
            break;

        case 'sin':
            printf("Enter an angle in radians to find the sine: ");
            scanf("%lf", &num1);
            result = sin(num1);
            printf("sin(%.2lf) = %.2lf", num1, result);
            break;

        case 'cos':
            printf("Enter an angle in radians to find the cosine: ");
            scanf("%lf", &num1);
            result = cos(num1);
            printf("cos(%.2lf) = %.2lf", num1, result);
            break;

        case 'tan':
            printf("Enter an angle in radians to find the tangent: ");
            scanf("%lf", &num1);
            result = tan(num1);
            printf("tan(%.2lf) = %.2lf", num1, result);
            break;

        case 'log':
            printf("Enter a number to find the natural logarithm: ");
            scanf("%lf", &num1);
            result = log(num1);
            printf("ln(%.2lf) = %.2lf", num1, result);
            break;

        case 'sqrt':
            printf("Enter a number to find the square root: ");
            scanf("%lf", &num1);
            if(num1 >= 0) {
                result = sqrt(num1);
                printf("sqrt(%.2lf) = %.2lf", num1, result);
            } else {
                printf("Error: square root of a negative number");
            }
            break;

        default:
            printf("Invalid operator");
            break;
    }

    return 0;
}