//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main() {
  int matrixA[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  int matrixB[ROWS][COLS] = {
    {13, 14, 15, 16},
    {17, 18, 19, 20},
    {21, 22, 23, 24}
  };

  printf("Matrix A:\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrixA[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix B:\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrixB[i][j]);
    }
    printf("\n");
  }

  printf("\nSum of Matrix A and Matrix B:\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrixA[i][j] + matrixB[i][j]);
    }
    printf("\n");
  }

  printf("\nDifference of Matrix A and Matrix B:\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrixA[i][j] - matrixB[i][j]);
    }
    printf("\n");
  }

  printf("\nProduct of Matrix A and Matrix B:\n");
  int product[ROWS][COLS];
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      product[i][j] = 0;
      for (int k = 0; k < COLS; k++) {
        product[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", product[i][j]);
    }
    printf("\n");
  }

  return 0;
}