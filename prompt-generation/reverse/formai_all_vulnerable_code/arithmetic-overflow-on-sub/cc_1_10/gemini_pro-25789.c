//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n <= 1) return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate the nth prime number
int prime(int n) {
  int i, j, count = 0;
  for (i = 2;; i++) {
    for (j = 2; j <= i / 2; j++) {
      if (i % j == 0) break;
    }
    if (j == i / 2 + 1) count++;
    if (count == n) return i;
  }
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

// Main function
int main() {
  // Get the user's input
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  // Calculate the factorial of the number
  int factorial_result = factorial(n);
  printf("The factorial of %d is %d\n", n, factorial_result);

  // Calculate the nth Fibonacci number
  int fibonacci_result = fibonacci(n);
  printf("The nth Fibonacci number is %d\n", n, fibonacci_result);

  // Calculate the nth prime number
  int prime_result = prime(n);
  printf("The nth prime number is %d\n", n, prime_result);

  // Calculate the greatest common divisor of two numbers
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);
  int gcd_result = gcd(a, b);
  printf("The greatest common divisor of %d and %d is %d\n", a, b, gcd_result);

  // Calculate the least common multiple of two numbers
  int lcm_result = lcm(a, b);
  printf("The least common multiple of %d and %d is %d\n", a, b, lcm_result);

  return 0;
}