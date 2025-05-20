//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
/*
 * Scientific Calculator Implementation in C
 *
 * This program implements a basic scientific calculator
 * with the following features:
 *
 * - Basic arithmetic operations (add, subtract, multiply, divide)
 * - Square root, exponential, and logarithmic functions
 * - Trigonometric functions (sin, cos, tan)
 * - Inverse trigonometric functions (asin, acos, atan)
 * - Degree/radian conversion
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <math.h>

// Define the constants for the calculator
#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4
#define SQRT 5
#define EXP 6
#define LOG 7
#define SIN 8
#define COS 9
#define TAN 10
#define ASIN 11
#define ACOS 12
#define ATAN 13
#define DEG2RAD 14
#define RAD2DEG 15

// Define the input and output format
#define INPUT_FORMAT "%lf"
#define OUTPUT_FORMAT "%.4lf"

// Define the functions
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double sqrt(double x);
double exp(double x);
double log(double x);
double sin(double x);
double cos(double x);
double tan(double x);
double asin(double x);
double acos(double x);
double atan(double x);
double deg2rad(double x);
double rad2deg(double x);

// Define the main function
int main() {
    // Define the variables
    double x, y, result;
    int operation;

    // Get the input from the user
    printf("Enter the first number: ");
    scanf(INPUT_FORMAT, &x);
    printf("Enter the second number: ");
    scanf(INPUT_FORMAT, &y);
    printf("Enter the operation (+, -, *, /, sqrt, exp, log, sin, cos, tan, asin, acos, atan, deg2rad, rad2deg): ");
    scanf("%d", &operation);

    // Perform the operation
    switch (operation) {
        case ADD:
            result = add(x, y);
            break;
        case SUBTRACT:
            result = subtract(x, y);
            break;
        case MULTIPLY:
            result = multiply(x, y);
            break;
        case DIVIDE:
            result = divide(x, y);
            break;
        case SQRT:
            result = sqrt(x);
            break;
        case EXP:
            result = exp(x);
            break;
        case LOG:
            result = log(x);
            break;
        case SIN:
            result = sin(x);
            break;
        case COS:
            result = cos(x);
            break;
        case TAN:
            result = tan(x);
            break;
        case ASIN:
            result = asin(x);
            break;
        case ACOS:
            result = acos(x);
            break;
        case ATAN:
            result = atan(x);
            break;
        case DEG2RAD:
            result = deg2rad(x);
            break;
        case RAD2DEG:
            result = rad2deg(x);
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }

    // Print the result
    printf("Result: " OUTPUT_FORMAT "\n", result);

    return 0;
}

// Define the functions
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

double sqrt(double x) {
    return sqrt(x);
}

double exp(double x) {
    return exp(x);
}

double log(double x) {
    return log(x);
}

double sin(double x) {
    return sin(x);
}

double cos(double x) {
    return cos(x);
}

double tan(double x) {
    return tan(x);
}

double asin(double x) {
    return asin(x);
}

double acos(double x) {
    return acos(x);
}

double atan(double x) {
    return atan(x);
}

double deg2rad(double x) {
    return deg2rad(x);
}

double rad2deg(double x) {
    return rad2deg(x);
}