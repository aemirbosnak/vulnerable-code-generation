//Code Llama-13B DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
/*
* Benchmarking Example Program in C
* By John Doe
*
* This program is designed to demonstrate the use of C for benchmarking.
* It measures the performance of different types of computations and prints
* the results to the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to measure the execution time of a block of code
double measure(void (*func)()) {
  clock_t start, end;
  start = clock();
  func();
  end = clock();
  return (double)(end - start) / CLOCKS_PER_SEC;
}

// Function to compute the factorial of a number
int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

// Function to compute the Fibonacci sequence
int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Main function
int main() {
  // Print the header
  printf("Benchmarking Example Program in C\n");
  printf("---------------------------------\n");

  // Measure the execution time of the factorial function
  double time_factorial = measure(factorial);
  printf("Factorial function execution time: %.2f seconds\n", time_factorial);

  // Measure the execution time of the Fibonacci function
  double time_fibonacci = measure(fibonacci);
  printf("Fibonacci function execution time: %.2f seconds\n", time_fibonacci);

  // Print the results
  printf("Factorial function is %.2f times faster than Fibonacci function\n", time_fibonacci / time_factorial);

  return 0;
}