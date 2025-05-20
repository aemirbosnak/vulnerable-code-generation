//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>

int main() {
    double num1, num2, result;
    char operation;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("Enter the operation (+, -, *, / or *sin, *cos, *tan): ");
    scanf(" %c", &operation);

    switch(operation) {
        case '+':
            result = num1 + num2;
            printf("The result is %lf\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("The result is %lf\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("The result is %lf\n", result);
            break;

        case '/':
            if(num2!= 0)
                result = num1 / num2;
            else
                printf("Division by zero!\n");
            printf("The result is %lf\n", result);
            break;

        case '*sin':
            result = num1 * sin(num2);
            printf("The result is %lf\n", result);
            break;

        case '*cos':
            result = num1 * cos(num2);
            printf("The result is %lf\n", result);
            break;

        case '*tan':
            result = num1 * tan(num2);
            printf("The result is %lf\n", result);
            break;

        default:
            printf("Invalid operation!\n");
    }

    return 0;
}