//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES

// Function to calculate the square root of a number
double squareroot(double n) {
  double x = n / 2;
  while (fabs(x * x - n) > 1e-9) {
    x = (x + n / x) / 2;
  }
  return x;
}

// Function to calculate the factorial of a number
double factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the natural logarithm of a number
double naturallog(double n) {
  double x = 1;
  int i = 1;
  while (fabs(x - n) > 1e-9) {
    x += 1.0 / i;
    i++;
  }
  return x;
}

// Main function
int main() {
  // Get the input from the user
  printf("Please enter a number: ");
  double n;
  scanf("%lf", &n);

  // Calculate the square root, factorial, and natural logarithm of the number
  double sqr = squareroot(n);
  double fact = factorial(n);
  double ln = naturallog(n);

  // Print the results
  printf("The square root of %f is %f\n", n, sqr);
  printf("The factorial of %d is %f\n", n, fact);
  printf("The natural logarithm of %f is %f\n", n, ln);

  return 0;
}