//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to compute the Fibonacci sequence
int fibonacci(int n) {
  if (n == 0 || n == 1) return n;
  return fibonacci(n-1) + fibonacci(n-2);
}

// Function to compute the golden ratio
double golden_ratio(int n) {
  return (sqrt(n) + sqrt(n+1)) / 2;
}

// Function to compute the tribonacci sequence
int tribonacci(int n) {
  if (n == 0 || n == 1) return n;
  return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
}

int main() {
  int n, m;
  double d;

  // Input values
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  printf("Enter a positive integer: ");
  scanf("%d", &m);

  // Compute Fibonacci sequence
  for (int i = 0; i <= n; i++) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");

  // Compute golden ratio
  for (int i = 0; i <= m; i++) {
    d = golden_ratio(i);
    printf("%.2f ", d);
  }
  printf("\n");

  // Compute tribonacci sequence
  for (int i = 0; i <= n; i++) {
    printf("%d ", tribonacci(i));
  }
  printf("\n");

  return 0;
}