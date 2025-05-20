//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter operator (+, -, *, /, %%): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;

        case '/':
            if(num2 == 0) {
                printf("Error: Cannot divide by zero.");
            } else {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            }
            break;

        case '%':
            if(isnan(num1) || isnan(num2)) {
                printf("Error: Invalid input.");
            } else {
                result = fmod(num1, num2);
                printf("Result: %.2lf\n", result);
            }
            break;

        default:
            printf("Error: Invalid operator.");
    }

    return 0;
}