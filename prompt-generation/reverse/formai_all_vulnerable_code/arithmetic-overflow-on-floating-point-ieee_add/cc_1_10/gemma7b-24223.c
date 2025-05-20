//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    double (*op_func)(double, double);
    char op;
    struct Calculator* next;
} Calculator;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        return -1;
    }
    return a / b;
}

void calculate(char op, double num1, double num2) {
    double result;
    Calculator* calc = NULL;

    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            result = -1;
            break;
    }

    if (result != -1) {
        printf("%f\n", result);
    } else {
        printf("Error\n");
    }
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    double num1, num2;
    char op;

    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &op);

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    calculate(op, num1, num2);

    return 0;
}