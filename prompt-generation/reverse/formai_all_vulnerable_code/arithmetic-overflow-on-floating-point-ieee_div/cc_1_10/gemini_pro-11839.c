//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform basic arithmetic operations
double basic_arithmetic(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

// Function to perform trigonometric operations
double trigonometric(double a, char op) {
    switch (op) {
        case 'sin':
            return sin(a);
        case 'cos':
            return cos(a);
        case 'tan':
            return tan(a);
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

// Function to perform exponential and logarithmic operations
double exponential_logarithmic(double a, char op) {
    switch (op) {
        case 'exp':
            return exp(a);
        case 'log':
            return log(a);
        case 'pow':
            return pow(a, 2); // Assuming power is always 2
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

// Function to perform a specific operation based on the user's choice
double calculate(double a, double b, char op) {
    switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
            return basic_arithmetic(a, b, op);
        case 'sin':
        case 'cos':
        case 'tan':
            return trigonometric(a, op);
        case 'exp':
        case 'log':
        case 'pow':
            return exponential_logarithmic(a, op);
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

// Function to get the user's input
void get_input(double *a, double *b, char *op) {
    printf("Enter the first number: ");
    scanf("%lf", a);
    printf("Enter the second number: ");
    scanf("%lf", b);
    printf("Enter the operator (+, -, *, /, sin, cos, tan, exp, log, pow): ");
    scanf(" %c", op); // Add a space before %c to avoid reading the newline character
}

int main() {
    double a, b;
    char op;

    get_input(&a, &b, &op);
    double result = calculate(a, b, op);
    printf("The result is: %lf\n", result);

    return 0;
}