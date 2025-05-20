//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <math.h>
#include <string.h>

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

double squareRoot(double a) {
    return sqrt(a);
}

double sine(double a) {
    return sin(a);
}

double cosine(double a) {
    return cos(a);
}

double tangent(double a) {
    return tan(a);
}

int main() {
    double a, b, result;
    char operation[50];

    printf("Welcome to the Scientific Calculator!\n");
    printf("Please enter an operation (+, -, *, /, power, sqrt, sin, cos, tan): ");
    scanf("%s", operation);

    if (strcmp(operation, "+") == 0) {
        printf("Enter two numbers to add: ");
        scanf("%lf %lf", &a, &b);
        result = add(a, b);
    } else if (strcmp(operation, "-") == 0) {
        printf("Enter two numbers to subtract: ");
        scanf("%lf %lf", &a, &b);
        result = subtract(a, b);
    } else if (strcmp(operation, "*") == 0) {
        printf("Enter two numbers to multiply: ");
        scanf("%lf %lf", &a, &b);
        result = multiply(a, b);
    } else if (strcmp(operation, "/") == 0) {
        printf("Enter two numbers to divide: ");
        scanf("%lf %lf", &a, &b);
        result = divide(a, b);
    } else if (strcmp(operation, "power") == 0) {
        printf("Enter two numbers to power: ");
        scanf("%lf %lf", &a, &b);
        result = power(a, b);
    } else if (strcmp(operation, "sqrt") == 0) {
        printf("Enter a number to square root: ");
        scanf("%lf", &a);
        result = squareRoot(a);
    } else if (strcmp(operation, "sin") == 0) {
        printf("Enter a number to get the sine: ");
        scanf("%lf", &a);
        result = sine(a);
    } else if (strcmp(operation, "cos") == 0) {
        printf("Enter a number to get the cosine: ");
        scanf("%lf", &a);
        result = cosine(a);
    } else if (strcmp(operation, "tan") == 0) {
        printf("Enter a number to get the tangent: ");
        scanf("%lf", &a);
        result = tangent(a);
    } else {
        printf("Invalid operation!");
        return -1;
    }

    printf("Result: %lf\n", result);

    return 0;
}