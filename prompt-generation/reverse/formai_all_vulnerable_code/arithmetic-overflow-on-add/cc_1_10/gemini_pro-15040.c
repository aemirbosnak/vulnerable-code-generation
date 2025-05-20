//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>

// Define the maximum number of Fibonacci numbers to generate
#define MAX_FIB 100

// Declare an array to store the Fibonacci numbers
int fib[MAX_FIB];

// Function to generate the Fibonacci sequence
void generate_fibonacci() {
  // Initialize the first two Fibonacci numbers
  fib[0] = 0;
  fib[1] = 1;

  // Generate the remaining Fibonacci numbers
  for (int i = 2; i < MAX_FIB; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
}

// Function to print the Fibonacci sequence
void print_fibonacci() {
  // Print the Fibonacci numbers
  for (int i = 0; i < MAX_FIB; i++) {
    printf("%d ", fib[i]);
  }

  // Print a newline character
  printf("\n");
}

// Function to visualize the Fibonacci sequence
void visualize_fibonacci() {
  // Initialize the visualization grid
  int grid[MAX_FIB][MAX_FIB];

  // Fill the visualization grid with zeros
  for (int i = 0; i < MAX_FIB; i++) {
    for (int j = 0; j < MAX_FIB; j++) {
      grid[i][j] = 0;
    }
  }

  // Draw the Fibonacci spiral
  int x = 0;
  int y = 0;
  int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up
  for (int i = 0; i < MAX_FIB; i++) {
    // Draw a square with side length equal to the Fibonacci number
    for (int j = 0; j < fib[i]; j++) {
      switch (direction) {
        case 0:
          x++;
          break;
        case 1:
          y++;
          break;
        case 2:
          x--;
          break;
        case 3:
          y--;
          break;
      }

      // Fill the square with the Fibonacci number
      grid[x][y] = fib[i];
    }

    // Change the direction
    direction = (direction + 1) % 4;
  }

  // Print the visualization grid
  for (int i = 0; i < MAX_FIB; i++) {
    for (int j = 0; j < MAX_FIB; j++) {
      printf("%d ", grid[i][j]);
    }

    // Print a newline character
    printf("\n");
  }
}

// Main function
int main() {
  // Generate the Fibonacci sequence
  generate_fibonacci();

  // Print the Fibonacci sequence
  print_fibonacci();

  // Visualize the Fibonacci sequence
  visualize_fibonacci();

  return 0;
}