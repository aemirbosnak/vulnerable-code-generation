//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: scientific
#include <stdio.h>
#include <math.h>

// Forward declaration of functions
double compute_pi(int n);
double compute_exponential(double x, int n);
double compute_factorial(int n);

// Main function
int main() {
  // Declare variables
  int n;
  double x;

  // Prompt the user to enter a value for n
  printf("Enter a positive integer n: ");
  scanf("%d", &n);

  // Prompt the user to enter a value for x
  printf("Enter a real number x: ");
  scanf("%lf", &x);

  // Compute pi using the Leibniz series
  double pi = compute_pi(n);

  // Compute the exponential function using the Taylor series
  double exponential = compute_exponential(x, n);

  // Compute the factorial of n
  double factorial = compute_factorial(n);

  // Print the results
  printf("Pi is approximately: %.10f\n", pi);
  printf("The exponential of %lf is approximately: %.10f\n", x, exponential);
  printf("The factorial of %d is: %.0f\n", n, factorial);

  return 0;
}

// Function to compute pi using the Leibniz series
double compute_pi(int n) {
  // Initialize the sum
  double sum = 0.0;

  // Compute the sum of the first n terms of the series
  for (int i = 0; i < n; i++) {
    sum += (pow(-1, i) / (2 * i + 1));
  }

  // Return the sum of the series
  return 4 * sum;
}

// Function to compute the exponential function using the Taylor series
double compute_exponential(double x, int n) {
  // Initialize the sum
  double sum = 0.0;

  // Compute the sum of the first n terms of the series
  for (int i = 0; i < n; i++) {
    sum += (pow(x, i) / compute_factorial(i));
  }

  // Return the sum of the series
  return sum;
}

// Function to compute the factorial of n
double compute_factorial(int n) {
  // Base case
  if (n == 0) {
    return 1.0;
  }

  // Recursive case
  else {
    return n * compute_factorial(n - 1);
  }
}