//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the factorial of a given integer
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

// Function to calculate the sum of the first n Fibonacci numbers
int fibonacciSum(int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += fibonacci(i);
  }
  return sum;
}

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // Calculate the factorial of n
  int fact = factorial(n);
  printf("The factorial of %d is %d\n", n, fact);

  // Calculate the nth Fibonacci number
  int fib = fibonacci(n);
  printf("The nth Fibonacci number is %d\n", fib);

  // Calculate the sum of the first n Fibonacci numbers
  int sum = fibonacciSum(n);
  printf("The sum of the first %d Fibonacci numbers is %d\n", n, sum);

  return 0;
}