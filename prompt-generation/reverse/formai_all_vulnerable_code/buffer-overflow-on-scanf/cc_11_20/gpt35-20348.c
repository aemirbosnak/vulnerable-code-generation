//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char op;
    float num1, num2, result;

    printf("Welcome to Unique Calculator v1.0\n");
    printf("Enter an operation (+, -, *, /, sin, cos, tan, sqrt): ");
    scanf("%c", &op);

    switch(op) {
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;

        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;

        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;

        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            // check for division by zero
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                exit(0);
            }
            result = num1 / num2;
            printf("Result: %.2f\n", result);
            break;

        case 's':
            printf("Enter a number to find the sin: ");
            scanf("%f", &num1);
            result = sin(num1);
            printf("Result: %.2f\n", result);
            break;

        case 'c':
            printf("Enter a number to find the cos: ");
            scanf("%f", &num1);
            result = cos(num1);
            printf("Result: %.2f\n", result);
            break;

        case 't':
            printf("Enter a number to find the tan: ");
            scanf("%f", &num1);
            result = tan(num1);
            printf("Result: %.2f\n", result);
            break;

        case 'q':
            printf("Enter a number to find the square root: ");
            scanf("%f", &num1);
            if (num1 < 0) {
                printf("Error: Invalid input\n");
                exit(0);
            }
            result = sqrt(num1);
            printf("Result: %.2f\n", result);
            break;

        default:
            printf("Error: Invalid operation\n");
            break;
    }

    printf("Thank you for using Unique Calculator v1.0");
    return 0;
}