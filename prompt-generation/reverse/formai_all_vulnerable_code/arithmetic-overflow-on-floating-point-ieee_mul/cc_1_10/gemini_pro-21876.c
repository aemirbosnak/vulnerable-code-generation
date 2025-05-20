//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 100

// Define the error tolerance
#define ERROR_TOLERANCE 0.000001

// Define the function to be solved
double f(double x) {
    return x * x * x - 1;
}

// Define the derivative of the function to be solved
double df(double x) {
    return 3 * x * x;
}

// Implement the Newton-Raphson method
double newton_raphson(double initial_guess) {
    // Initialize the current guess
    double current_guess = initial_guess;

    // Iterate until the error is less than the tolerance or the maximum number of iterations is reached
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        // Calculate the next guess
        double next_guess = current_guess - f(current_guess) / df(current_guess);

        // Calculate the error
        double error = fabs(next_guess - current_guess);

        // Update the current guess
        current_guess = next_guess;

        // Check if the error is less than the tolerance
        if (error < ERROR_TOLERANCE) {
            return current_guess;
        }
    }

    // Return the current guess if the maximum number of iterations is reached
    return current_guess;
}

int main() {
    // Get the initial guess from the user
    printf("Enter the initial guess: ");
    double initial_guess;
    scanf("%lf", &initial_guess);

    // Solve the equation using the Newton-Raphson method
    double root = newton_raphson(initial_guess);

    // Print the root of the equation
    printf("The root of the equation is: %lf\n", root);

    return 0;
}