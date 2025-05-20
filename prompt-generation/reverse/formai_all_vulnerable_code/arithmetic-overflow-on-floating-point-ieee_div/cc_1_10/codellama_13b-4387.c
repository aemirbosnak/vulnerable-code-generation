//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: interoperable
/*
 * Scientific Calculator Implementation in C
 *
 * This program implements a simple scientific calculator that allows
 * the user to perform basic arithmetic operations such as addition,
 * subtraction, multiplication, and division. It also includes
 * functions for square root, factorial, and exponentiation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the functions
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double square_root(double x);
double factorial(int x);
double exponentiation(double x, double y);

// Main function
int main() {
    // Declare variables
    double x, y;
    char operation;

    // Get input from the user
    printf("Enter the first number: ");
    scanf("%lf", &x);
    printf("Enter the second number: ");
    scanf("%lf", &y);
    printf("Enter the operation (+, -, *, /, sqrt, fact, pow): ");
    scanf(" %c", &operation);

    // Perform the operation
    switch (operation) {
        case '+':
            printf("The sum is: %lf\n", add(x, y));
            break;
        case '-':
            printf("The difference is: %lf\n", subtract(x, y));
            break;
        case '*':
            printf("The product is: %lf\n", multiply(x, y));
            break;
        case '/':
            printf("The quotient is: %lf\n", divide(x, y));
            break;
        case 'sqrt':
            printf("The square root is: %lf\n", square_root(x));
            break;
        case 'fact':
            printf("The factorial is: %lf\n", factorial(x));
            break;
        case 'pow':
            printf("The exponentiation is: %lf\n", exponentiation(x, y));
            break;
        default:
            printf("Invalid operation\n");
            break;
    }

    return 0;
}

// Function definitions
double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    return x / y;
}

double square_root(double x) {
    return sqrt(x);
}

double factorial(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return x * factorial(x - 1);
    }
}

double exponentiation(double x, double y) {
    return pow(x, y);
}