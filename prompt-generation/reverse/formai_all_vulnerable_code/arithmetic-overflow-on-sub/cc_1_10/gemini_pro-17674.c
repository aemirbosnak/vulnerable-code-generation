//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the sum of the digits of a number
int sumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

// Function to check if a number is a prime number
int isPrime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

// Function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n1, n2;

  printf("Enter two numbers: ");
  scanf("%d %d", &n1, &n2);

  printf("Sum of the digits of %d: %d\n", n1, sumOfDigits(n1));
  printf("Sum of the digits of %d: %d\n", n2, sumOfDigits(n2));

  printf("%d is %s a prime number.\n", n1, isPrime(n1) ? "" : "not");
  printf("%d is %s a prime number.\n", n2, isPrime(n2) ? "" : "not");

  printf("GCD of %d and %d: %d\n", n1, n2, gcd(n1, n2));
  printf("LCM of %d and %d: %d\n", n1, n2, lcm(n1, n2));

  printf("Factorial of %d: %d\n", n1, factorial(n1));
  printf("Factorial of %d: %d\n", n2, factorial(n2));

  printf("Fibonacci number at position %d: %d\n", n1, fibonacci(n1));
  printf("Fibonacci number at position %d: %d\n", n2, fibonacci(n2));

  return 0;
}