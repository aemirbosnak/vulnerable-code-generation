//FormAI DATASET v1.0 Category: Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    // variable declaration
    char operator;
    double num1, num2;

    // prompt user for input
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // perform operation based on operator
    if (operator == '+') {
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, add(num1, num2));
    } else if (operator == '-') {
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, subtract(num1, num2));
    } else if (operator == '*') {
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, multiply(num1, num2));
    } else if (operator == '/') {
        if (num2 == 0) {
            printf("Error: cannot divide by zero\n");
        } else {
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, divide(num1, num2));
        }
    } else {
        printf("Error: operator is not valid\n");
    }

    return 0;
}

// function implementations
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
    return a / b;
}