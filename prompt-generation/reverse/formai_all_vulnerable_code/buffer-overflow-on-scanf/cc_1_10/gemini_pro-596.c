//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the Fibonacci sequence
int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Function to visualize the Fibonacci sequence
void visualize(int n) {
  int i, j;

  // Create a 2D array to store the Fibonacci sequence
  int **fib = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    fib[i] = (int *)malloc(n * sizeof(int));
  }

  // Calculate the Fibonacci sequence
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      fib[i][j] = fibonacci(i + j);
    }
  }

  // Print the Fibonacci sequence
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", fib[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the Fibonacci sequence
  for (i = 0; i < n; i++) {
    free(fib[i]);
  }
  free(fib);
}

// Main function
int main() {
  int n;

  // Get the number of terms in the Fibonacci sequence
  printf("Enter the number of terms in the Fibonacci sequence: ");
  scanf("%d", &n);

  // Visualize the Fibonacci sequence
  visualize(n);

  return 0;
}