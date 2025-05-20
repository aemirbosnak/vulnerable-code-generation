//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to calculate the nth Fibonacci number
long long fib(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

// Function to draw the Fibonacci sequence using ASCII characters
void draw_fibonacci(int n) {
  // Calculate the length of the longest Fibonacci number
  int max_length = 0;
  for (int i = 0; i < n; i++) {
    int length = snprintf(NULL, 0, "%lld", fib(i));
    if (length > max_length) {
      max_length = length;
    }
  }

  // Print the header
  printf("Fibonacci Sequence:\n");
  for (int i = 0; i < n; i++) {
    printf("%*lld ", max_length, fib(i));
  }
  printf("\n");

  // Print the ASCII representation
  for (int i = 0; i < n; i++) {
    int num_spaces = max_length - snprintf(NULL, 0, "%lld", fib(i));
    for (int j = 0; j < num_spaces; j++) {
      printf(" ");
    }
    printf("#");
    for (int j = 0; j < fib(i); j++) {
      printf("=");
    }
    printf("\n");
  }
}

int main() {
  // Get the number of Fibonacci numbers to generate
  int n;
  printf("Enter the number of Fibonacci numbers to generate: ");
  scanf("%d", &n);

  // Draw the Fibonacci sequence
  draw_fibonacci(n);

  return 0;
}