//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to calculate the factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Function to calculate the number of ways to climb n stairs
int climbStairs(int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 2;
  } else {
    return climbStairs(n - 1) + climbStairs(n - 2);
  }
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  // Calculate the factorial of n
  int factorial_result = factorial(n);
  printf("The factorial of %d is %d\n", n, factorial_result);

  // Calculate the nth Fibonacci number
  int fibonacci_result = fibonacci(n);
  printf("The nth Fibonacci number is %d\n", fibonacci_result);

  // Calculate the number of ways to climb n stairs
  int climbStairs_result = climbStairs(n);
  printf("The number of ways to climb %d stairs is %d\n", n, climbStairs_result);

  return 0;
}