//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: modular
// math_exercise.c

#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Function to calculate the power of a number
int power(int base, int exponent) {
  if (exponent == 0) {
    return 1;
  } else {
    return base * power(base, exponent - 1);
  }
}

int main() {
  int num, factorial_result, fibonacci_result, power_result;

  printf("Enter a number: ");
  scanf("%d", &num);

  // Calculate the factorial of the number
  factorial_result = factorial(num);
  printf("Factorial of %d is: %d\n", num, factorial_result);

  // Calculate the Fibonacci sequence of the number
  fibonacci_result = fibonacci(num);
  printf("Fibonacci sequence of %d is: %d\n", num, fibonacci_result);

  // Calculate the power of a number
  power_result = power(2, num);
  printf("2^%d is: %d\n", num, power_result);

  return 0;
}