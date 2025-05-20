//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <math.h>

// Function to print the result of the calculation
void printResult(double result) {
    printf("%lf\n", result);
}

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}

// Function to perform exponentiation
double power(double base, double exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    return base * power(base, exponent - 1);
}

// Function to perform trigonometric functions
double trigonometricFunction(double x, char function) {
    if (function =='s') {
        return sin(x);
    } else if (function == 'c') {
        return cos(x);
    } else if (function == 't') {
        return tan(x);
    } else {
        printf("Error: Invalid trigonometric function\n");
        return 0;
    }
}

// Main function to perform calculations
int main() {
    // Ask user for input
    printf("Enter the first number: ");
    double a;
    scanf("%lf", &a);
    printf("Enter the second number: ");
    double b;
    scanf("%lf", &b);

    // Perform calculations
    printf("Addition: %lf\n", add(a, b));
    printf("Subtraction: %lf\n", subtract(a, b));
    printf("Multiplication: %lf\n", multiply(a, b));
    printf("Division: %lf\n", divide(a, b));
    printf("Exponentiation: %lf\n", power(a, b));
    printf("Sine: %lf\n", trigonometricFunction(a,'s'));
    printf("Cosine: %lf\n", trigonometricFunction(a, 'c'));
    printf("Tangent: %lf\n", trigonometricFunction(a, 't'));

    return 0;
}