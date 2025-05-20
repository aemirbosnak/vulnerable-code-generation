//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define the error codes
#define ERR_INVALID_INPUT  1
#define ERR_DIVIDE_BY_ZERO 2
#define ERR_MATH_DOMAIN    3

// Define the function to calculate the square root
double square_root(double x) {
    if (x < 0) {
        return -1.0; // Return an error code for negative inputs
    }
    return sqrt(x);
}

// Define the function to calculate the reciprocal
double reciprocal(double x) {
    if (x == 0) {
        return -2.0; // Return an error code for division by zero
    }
    return 1.0 / x;
}

// Define the function to calculate the natural logarithm
double natural_log(double x) {
    if (x <= 0) {
        return -3.0; // Return an error code for non-positive inputs
    }
    return log(x);
}

// Define the main function
int main() {
    // Declare the variables
    double x, result;

    // Get the input from the user
    printf("Enter a number: ");
    scanf("%lf", &x);

    // Calculate the square root
    result = square_root(x);
    if (result < 0) { // Check for errors
        printf("Error: Invalid input.\n");
        return ERR_INVALID_INPUT;
    }
    printf("The square root of %lf is %lf.\n", x, result);

    // Calculate the reciprocal
    result = reciprocal(x);
    if (result < 0) { // Check for errors
        printf("Error: Division by zero.\n");
        return ERR_DIVIDE_BY_ZERO;
    }
    printf("The reciprocal of %lf is %lf.\n", x, result);

    // Calculate the natural logarithm
    result = natural_log(x);
    if (result < 0) { // Check for errors
        printf("Error: Non-positive input.\n");
        return ERR_MATH_DOMAIN;
    }
    printf("The natural logarithm of %lf is %lf.\n", x, result);

    return 0;
}