//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genius
/*
 * Scientific Calculator Implementation in C
 *
 * This program implements a basic scientific calculator in C.
 * It supports the following operations:
 * 1. Addition
 * 2. Subtraction
 * 3. Multiplication
 * 4. Division
 * 5. Exponentiation
 * 6. Square Root
 * 7. Factorial
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <math.h>

// Define the variables
double num1, num2, result;
char op;

// Define the functions
double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);
double pow(double, double);
double sqrt(double);
double fac(double);

int main() {
    // Take input from the user
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    printf("Enter the operation: ");
    scanf(" %c", &op);

    // Perform the operation
    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = sub(num1, num2);
            break;
        case '*':
            result = mul(num1, num2);
            break;
        case '/':
            result = div(num1, num2);
            break;
        case '^':
            result = pow(num1, num2);
            break;
        case 'S':
            result = sqrt(num1);
            break;
        case 'F':
            result = fac(num1);
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }

    // Print the result
    printf("Result: %lf\n", result);

    return 0;
}

// Define the functions
double add(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}

double mul(double x, double y) {
    return x * y;
}

double div(double x, double y) {
    return x / y;
}

double pow(double x, double y) {
    return pow(x, y);
}

double sqrt(double x) {
    return sqrt(x);
}

double fac(double x) {
    return fac(x);
}