//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 100000

// Define the tolerance for the error
#define TOLERANCE 1e-6

// Define the function to be solved
double f(double x) {
    return x * x - 2;
}

// Define the derivative of the function
double df(double x) {
    return 2 * x;
}

// Find the root of the function using the Newton-Raphson method
double newton_raphson(double initial_guess) {
    // Set the current guess to the initial guess
    double current_guess = initial_guess;

    // Iterate until the error is within the tolerance
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Calculate the next guess
        double next_guess = current_guess - f(current_guess) / df(current_guess);

        // Calculate the error
        double error = fabs(next_guess - current_guess);

        // If the error is within the tolerance, return the current guess
        if (error < TOLERANCE) {
            return current_guess;
        }

        // Otherwise, update the current guess
        current_guess = next_guess;
    }

    // If the maximum number of iterations is reached, return an error message
    fprintf(stderr, "Maximum number of iterations reached.\n");
    return NAN;
}

int main() {
    // Get the initial guess from the user
    double initial_guess;
    printf("Enter the initial guess: ");
    scanf("%lf", &initial_guess);

    // Find the root of the function
    double root = newton_raphson(initial_guess);

    // Print the root
    printf("The root of the function is: %f\n", root);

    return 0;
}