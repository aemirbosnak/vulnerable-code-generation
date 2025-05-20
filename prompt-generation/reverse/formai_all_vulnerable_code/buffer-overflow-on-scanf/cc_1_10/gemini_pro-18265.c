//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate the Fibonacci sequence
int* fibonacci(int n) {
  int* fib = malloc(sizeof(int) * n);
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib;
}

// Function to visualize the Fibonacci sequence as a bar chart
void visualize(int* fib, int n) {
  // Find the maximum value in the sequence
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (fib[i] > max) {
      max = fib[i];
    }
  }

  // Print the bar chart
  for (int i = 0; i < n; i++) {
    // Calculate the height of the bar
    int height = (int)((double)fib[i] / max * 50);

    // Print the bar
    for (int j = 0; j < height; j++) {
      printf("*");
    }

    // Print the newline character
    printf("\n");
  }
}

int main() {
  // Get the number of terms in the Fibonacci sequence
  int n;
  printf("Enter the number of terms in the Fibonacci sequence: ");
  scanf("%d", &n);

  // Generate the Fibonacci sequence
  int* fib = fibonacci(n);

  // Visualize the Fibonacci sequence
  visualize(fib, n);

  // Free the allocated memory
  free(fib);

  return 0;
}