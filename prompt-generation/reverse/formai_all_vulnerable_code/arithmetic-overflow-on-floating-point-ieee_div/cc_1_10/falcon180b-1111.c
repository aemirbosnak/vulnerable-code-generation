//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double sqrt(double a);
double sin(double a);
double cos(double a);
double tan(double a);

// Main function
int main() {
    char input[100];
    double num1, num2, result;
    int choice;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the operator (+, -, *, /, sqrt, sin, cos, tan): ");
    scanf(" %c", &choice);

    switch(choice) {
        case '+':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = add(num1, num2);
            printf("Result: %lf\n", result);
            break;
        case '-':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = subtract(num1, num2);
            printf("Result: %lf\n", result);
            break;
        case '*':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = multiply(num1, num2);
            printf("Result: %lf\n", result);
            break;
        case '/':
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = divide(num1, num2);
            printf("Result: %lf\n", result);
            break;
        case's':
            printf("Enter the number: ");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("Result: %lf\n", result);
            break;
        case 'n':
            printf("Enter the number: ");
            scanf("%lf", &num1);
            result = sin(num1);
            printf("Result: %lf\n", result);
            break;
        case 'c':
            printf("Enter the number: ");
            scanf("%lf", &num1);
            result = cos(num1);
            printf("Result: %lf\n", result);
            break;
        case 't':
            printf("Enter the number: ");
            scanf("%lf", &num1);
            result = tan(num1);
            printf("Result: %lf\n", result);
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }

    return 0;
}

// Function definitions
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

double power(double a, double b) {
    return pow(a, b);
}

double sqrt(double a) {
    return sqrt(a);
}

double sin(double a) {
    return sin(a);
}

double cos(double a) {
    return cos(a);
}

double tan(double a) {
    return tan(a);
}