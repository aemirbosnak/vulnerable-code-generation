//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations for the Newton-Raphson method
#define MAX_ITERATIONS 100

// Define the tolerance for the Newton-Raphson method
#define TOLERANCE 1e-6

// Define the function to find the root of
double f(double x) {
    return x * x - 2;
}

// Define the derivative of the function
double fprime(double x) {
    return 2 * x;
}

// Use the Newton-Raphson method to find the root of the function
double newton_raphson(double initial_guess) {
    double x = initial_guess;
    int iteration = 0;

    // Iterate until the tolerance is reached or the maximum number of iterations is reached
    while (fabs(f(x)) > TOLERANCE && iteration < MAX_ITERATIONS) {
        // Update the value of x using the Newton-Raphson formula
        x = x - f(x) / fprime(x);

        // Increment the iteration counter
        iteration++;
    }

    // Return the final value of x
    return x;
}

int main() {
    // Get the initial guess from the user
    double initial_guess;
    printf("Enter the initial guess for the Newton-Raphson method: ");
    scanf("%lf", &initial_guess);

    // Find the root of the function using the Newton-Raphson method
    double root = newton_raphson(initial_guess);

    // Print the root of the function
    printf("The root of the function is: %lf\n", root);

    return 0;
}