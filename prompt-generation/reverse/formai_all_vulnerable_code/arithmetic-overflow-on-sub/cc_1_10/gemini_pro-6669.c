//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BUF_SIZE 256
#define PI 3.14159265358979323846

// Function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the binomial coefficient
int binomial_coefficient(int n, int k) {
  return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to calculate the sum of the first n terms of a geometric series
double geometric_series_sum(double a, double r, int n) {
  if (r == 1) {
    return a * n;
  } else {
    return a * (1 - pow(r, n)) / (1 - r);
  }
}

// Function to calculate the area of a circle
double circle_area(double radius) {
  return PI * pow(radius, 2);
}

// Function to calculate the volume of a sphere
double sphere_volume(double radius) {
  return (4 / 3) * PI * pow(radius, 3);
}

// Function to calculate the surface area of a sphere
double sphere_surface_area(double radius) {
  return 4 * PI * pow(radius, 2);
}

// Function to calculate the quadratic formula
double quadratic_formula(double a, double b, double c) {
  double discriminant = pow(b, 2) - 4 * a * c;
  if (discriminant < 0) {
    return NAN;
  } else {
    return (-b + sqrt(discriminant)) / (2 * a);
  }
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

// Function to calculate the prime factorization of a number
void prime_factorization(int n) {
  printf("%d = ", n);
  for (int i = 2; i <= n / i; i++) {
    while (n % i == 0) {
      printf("%d ", i);
      n /= i;
    }
  }
  if (n > 1) {
    printf("%d ", n);
  }
  printf("\n");
}

int main() {
  // Buffer for user input
  char buf[BUF_SIZE];

  // Get user input
  printf("Enter a number: ");
  fgets(buf, BUF_SIZE, stdin);

  // Convert the input to an integer
  int n = atoi(buf);

  // Calculate the factorial of the number
  int factorial_n = factorial(n);

  // Print the result
  printf("The factorial of %d is %d\n", n, factorial_n);

  return 0;
}