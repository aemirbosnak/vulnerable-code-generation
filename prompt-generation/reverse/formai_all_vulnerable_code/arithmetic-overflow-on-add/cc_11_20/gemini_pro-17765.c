//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FIB_TERMS 100

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create an array to store the Fibonacci sequence
  int fib_sequence[NUM_FIB_TERMS];

  // Initialize the first two terms of the sequence
  fib_sequence[0] = 0;
  fib_sequence[1] = 1;

  // Calculate the remaining terms of the sequence
  for (int i = 2; i < NUM_FIB_TERMS; i++) {
    fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
  }

  // Print the Fibonacci sequence
  for (int i = 0; i < NUM_FIB_TERMS; i++) {
    printf("%d ", fib_sequence[i]);
  }

  printf("\n");

  // Create a 2D array to store the Fibonacci spiral
  int fib_spiral[NUM_FIB_TERMS][NUM_FIB_TERMS];

  // Initialize the spiral with zeros
  for (int i = 0; i < NUM_FIB_TERMS; i++) {
    for (int j = 0; j < NUM_FIB_TERMS; j++) {
      fib_spiral[i][j] = 0;
    }
  }

  // Place the Fibonacci sequence in the spiral
  int row = 0;
  int col = 0;
  int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up
  for (int i = 0; i < NUM_FIB_TERMS; i++) {
    fib_spiral[row][col] = fib_sequence[i];

    // Determine the next direction to move in
    switch (direction) {
      case 0:
        if (col + 1 < NUM_FIB_TERMS && fib_spiral[row][col + 1] == 0) {
          col++;
        } else {
          direction = 1;
          row++;
        }
        break;
      case 1:
        if (row + 1 < NUM_FIB_TERMS && fib_spiral[row + 1][col] == 0) {
          row++;
        } else {
          direction = 2;
          col--;
        }
        break;
      case 2:
        if (col - 1 >= 0 && fib_spiral[row][col - 1] == 0) {
          col--;
        } else {
          direction = 3;
          row--;
        }
        break;
      case 3:
        if (row - 1 >= 0 && fib_spiral[row - 1][col] == 0) {
          row--;
        } else {
          direction = 0;
          col++;
        }
        break;
    }
  }

  // Print the Fibonacci spiral
  for (int i = 0; i < NUM_FIB_TERMS; i++) {
    for (int j = 0; j < NUM_FIB_TERMS; j++) {
      printf("%d ", fib_spiral[i][j]);
    }
    printf("\n");
  }

  return 0;
}