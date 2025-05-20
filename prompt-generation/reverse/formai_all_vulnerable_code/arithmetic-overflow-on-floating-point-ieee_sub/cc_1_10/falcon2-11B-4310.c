//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int operation;
    double num1, num2, result;

    printf("Welcome to the Paranoid Scientific Calculator!\n");
    printf("Please enter an operation (+, -, *, /): ");
    scanf("%d", &operation);

    switch (operation) {
        case '+':
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("The result is %.2lf\n", result);
            break;

        case '-':
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("The result is %.2lf\n", result);
            break;

        case '*':
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("The result is %.2lf\n", result);
            break;

        case '/':
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = num1 / num2;
            printf("The result is %.2lf\n", result);
            break;

        default:
            printf("Invalid operation!\n");
            break;
    }

    return 0;
}