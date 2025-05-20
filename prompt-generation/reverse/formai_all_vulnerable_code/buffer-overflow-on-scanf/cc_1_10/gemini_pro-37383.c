//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 100

// Define the tolerance for the convergence criterion
#define TOLERANCE 1e-6

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
  // Initialize the current guess
  double x = initial_guess;

  // Iterate until the convergence criterion is met
  for (int i = 0; i < MAX_ITERATIONS; i++) {
    // Calculate the next guess
    double next_x = x - f(x) / fprime(x);

    // Check if the convergence criterion is met
    if (fabs(next_x - x) < TOLERANCE) {
      return next_x;
    }

    // Update the current guess
    x = next_x;
  }

  // Return the final guess if the convergence criterion was not met
  return x;
}

// Implement the main function
int main() {
  // Get the initial guess from the user
  double initial_guess;
  printf("Enter the initial guess: ");
  scanf("%lf", &initial_guess);

  // Solve the equation using the Newton-Raphson method
  double root = newton_raphson(initial_guess);

  // Print the result
  printf("The root of the equation is: %.6f\n", root);

  return 0;
}