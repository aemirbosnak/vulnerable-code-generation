//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the error tolerance
#define ERROR_TOLERANCE 0.000001

// Define the function to be solved
double f(double x) {
  return x * x - 2;
}

// Define the derivative of the function
double fprime(double x) {
  return 2 * x;
}

// Implement the Newton-Raphson method
double newton_raphson(double initial_guess) {
  // Initialize the iteration counter
  int iteration = 0;

  // Iterate until the error is below the tolerance or the maximum number of iterations is reached
  while (iteration < MAX_ITERATIONS) {
    // Compute the next approximation
    double next_approximation = initial_guess - f(initial_guess) / fprime(initial_guess);

    // Compute the error
    double error = fabs(next_approximation - initial_guess);

    // Check if the error is below the tolerance
    if (error < ERROR_TOLERANCE) {
      return next_approximation;
    }

    // Update the initial guess
    initial_guess = next_approximation;

    // Increment the iteration counter
    iteration++;
  }

  // If the maximum number of iterations is reached, return an error
  return NAN;
}

int main() {
  // Prompt the user to enter the initial guess
  printf("Enter the initial guess: ");
  double initial_guess;
  scanf("%lf", &initial_guess);

  // Compute the root using the Newton-Raphson method
  double root = newton_raphson(initial_guess);

  // Print the root
  if (!isnan(root)) {
    printf("The root is: %.6f\n", root);
  } else {
    printf("The method did not converge.\n");
  }

  return 0;
}