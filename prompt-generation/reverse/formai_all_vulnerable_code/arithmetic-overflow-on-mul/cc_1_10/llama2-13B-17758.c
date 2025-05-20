//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the benchmark function
int benchmark(int n) {
  // Generate a random number between 1 and n
  int x = (int)((double)rand() / RAND_MAX * n) + 1;

  // Calculate the factorial of x
  int y = factorial(x);

  // Calculate the sum of the first n positive integers
  int z = sum(n);

  // Return the difference between the factorial and the sum
  return y - z;
}

// Define the factorial function
int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

// Define the sum function
int sum(int n) {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    result += i;
  }
  return result;
}

int main() {
  // Set the number of iterations
  int n = 100000;

  // Initialize the timer
  clock_t start = clock();

  // Run the benchmark function n times
  for (int i = 0; i < n; i++) {
    benchmark(n);
  }

  // Get the time taken by the benchmark
  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  // Print the results
  printf("Benchmark Results:\n");
  printf("  Number of Iterations: %d\n", n);
  printf("  Time Taken (secs): %f\n", time_taken);
  printf("  Average Time per Iteration: %f\n", time_taken / n);

  return 0;
}