//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number
int fib(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

// Function to print the Fibonacci sequence up to the nth term
void print_fib(int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", fib(i));
  }
  printf("\n");
}

// Function to generate a graphical representation of the Fibonacci sequence
void visualize_fib(int n) {
  int max_width = 0;

  // Calculate the maximum width of the graphical representation
  for (int i = 0; i < n; i++) {
    int width = fib(i) * 2;
    if (width > max_width) {
      max_width = width;
    }
  }

  // Create a 2D array to store the graphical representation
  char **grid = malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    grid[i] = malloc(sizeof(char) * max_width);
  }

  // Fill the grid with spaces
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < max_width; j++) {
      grid[i][j] = ' ';
    }
  }

  // Draw the Fibonacci sequence in the grid
  int x = 0;
  int y = 0;
  for (int i = 0; i < n; i++) {
    int width = fib(i) * 2;
    for (int j = 0; j < width; j++) {
      grid[y][x + j] = '*';
    }
    x += width;
    y++;
  }

  // Print the grid
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < max_width; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the grid
  for (int i = 0; i < n; i++) {
    free(grid[i]);
  }
  free(grid);
}

int main() {
  int n;

  // Get the number of terms from the user
  printf("Enter the number of terms: ");
  scanf("%d", &n);

  // Print the Fibonacci sequence
  printf("Fibonacci sequence: ");
  print_fib(n);

  // Generate the graphical representation of the Fibonacci sequence
  printf("Graphical representation of the Fibonacci sequence:\n");
  visualize_fib(n);

  return 0;
}