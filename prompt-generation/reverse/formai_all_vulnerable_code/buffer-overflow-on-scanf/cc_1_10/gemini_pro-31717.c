//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Fibonacci number at a given index
long fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Function to print the Fibonacci sequence up to a given index
void print_fibonacci(int n) {
  for (int i = 0; i < n; i++) {
    printf("%ld ", fibonacci(i));
  }
  printf("\n");
}

// Function to generate a visual representation of the Fibonacci sequence
void visualize_fibonacci(int n) {
  // Initialize the array to store the Fibonacci numbers
  long *fib_array = malloc(n * sizeof(long));

  // Calculate the Fibonacci numbers and store them in the array
  for (int i = 0; i < n; i++) {
    fib_array[i] = fibonacci(i);
  }

  // Find the maximum Fibonacci number to determine the width of the visualization
  long max_fib = fib_array[n - 1];
  int max_fib_width = snprintf(NULL, 0, "%ld", max_fib);

  // Print the header of the visualization
  printf("%*s", max_fib_width, "");
  for (int i = 0; i < n; i++) {
    printf("%*s", max_fib_width, "");
  }
  printf("\n");

  // Print the Fibonacci numbers in a visual format
  for (int i = 0; i < n; i++) {
    printf("%*ld", max_fib_width, fib_array[i]);
  }
  printf("\n");

  // Free the allocated memory
  free(fib_array);
}

int main() {
  // Get the number of Fibonacci numbers to generate from the user
  int n;
  printf("Enter the number of Fibonacci numbers to generate: ");
  scanf("%d", &n);

  // Print the Fibonacci sequence
  printf("The Fibonacci sequence up to %d is: ", n);
  print_fibonacci(n);

  // Visualize the Fibonacci sequence
  printf("Visual representation of the Fibonacci sequence up to %d:\n", n);
  visualize_fibonacci(n);

  return 0;
}