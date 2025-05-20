//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main() {
  int a[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };
  int b[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };
  int c[ROWS][COLS];

  // Addition
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  // Subtraction
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      c[i][j] = a[i][j] - b[i][j];
    }
  }

  // Multiplication
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      c[i][j] = 0;
      for (int k = 0; k < COLS; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Transpose
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      c[i][j] = a[j][i];
    }
  }

  // Print the results
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}