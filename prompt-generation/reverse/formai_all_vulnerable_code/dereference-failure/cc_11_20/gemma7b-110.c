//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
  int **a = NULL;
  int **b = NULL;
  int **c = NULL;
  int rows = 3;
  int cols = 4;

  a = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    a[i] = (int *)malloc(cols * sizeof(int));
  }

  b = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    b[i] = (int *)malloc(cols * sizeof(int));
  }

  c = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    c[i] = (int *)malloc(cols * sizeof(int));
  }

  // Matrix Operations
  a[1][2] = 10;
  b[2][3] = 20;
  c[0][1] = 30;

  printf("The elements of matrix a are:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("The elements of matrix b are:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  printf("The elements of matrix c are:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (int i = 0; i < rows; i++) {
    free(a[i]);
  }
  free(a);

  for (int i = 0; i < rows; i++) {
    free(b[i]);
  }
  free(b);

  for (int i = 0; i < rows; i++) {
    free(c[i]);
  }
  free(c);
}