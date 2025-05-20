//FormAI DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>

/* This program is a complex C arithmetic example that */

int main() {
    float num1;
    float num2;
    char operator;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    float result;

    if (operator == '+') {
        result = num1 + num2;
    } else if (operator == '-') {
        result = num1 - num2;
    } else if (operator == '*') {
        result = num1 * num2;
    } else if (operator == '/') {
        if (num2 == 0) {
            printf("Error: Dividing by zero!\n");
            return 1;
        } else {
            result = num1 / num2;
        }
    } else {
        printf("Error: Invalid operator '%c'\n", operator);
        return 1;
    }

    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);

    if (result > 0) {
        printf("%.2f is positive\n", result);
    } else if (result < 0) {
        printf("%.2f is negative\n", result);
    } else {
        printf("%.2f is zero\n", result);
    }

    if (result == (int)result) {
        printf("%.2f is an integer\n", result);
    } else {
        printf("%.2f is not an integer\n", result);
    }

    for (int i = 1; i <= (int)result; i++) {
        if ((int)result % i == 0) {
            printf("%d is a factor of %.2f\n", i, result);
        }
    }

    printf("Thank you for using this program!\n");

    return 0;
}