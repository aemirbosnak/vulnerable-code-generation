//FormAI DATASET v1.0 Category: Calculator ; Style: calm
#include <stdio.h>

// function declarations
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {
    float num1, num2, result;
    char operator;

    printf("Please enter an arithmetic expression with two operands and one operator:\n");
    scanf("%f %c %f", &num1, &operator, &num2);

    switch (operator) {
    case '+':
        result = add(num1, num2);
        printf("%f + %f = %f\n", num1, num2, result);
        break;
    case '-':
        result = subtract(num1, num2);
        printf("%f - %f = %f\n", num1, num2, result);
        break;
    case '*':
        result = multiply(num1, num2);
        printf("%f * %f = %f\n", num1, num2, result);
        break;
    case '/':
        if (num2 == 0) {
            printf("Error: Cannot divide by zero\n");
            break;
        }
        result = divide(num1, num2);
        printf("%f / %f = %f\n", num1, num2, result);
        break;
    default:
        printf("Error: Invalid arithmetic operator\n");
        break;
    }

    return 0;
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}