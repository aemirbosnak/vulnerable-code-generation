//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>

int main() {
  int row, col, i, j;
  int a[10][10], b[10][10], c[10][10];

  printf("Enter number of rows (max 10): ");
  scanf("%d", &row);
  printf("Enter number of columns (max 10): ");
  scanf("%d", &col);

  // Get input for Matrix A
  printf("\nEnter Matrix A elements:\n");
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      printf("Enter element A[%d][%d]: ", i, j);
      scanf("%d", &a[i][j]);
    }
  }

  // Get input for Matrix B
  printf("\nEnter Matrix B elements:\n");
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      printf("Enter element B[%d][%d]: ", i, j);
      scanf("%d", &b[i][j]);
    }
  }

  // Multiply A and B matrices and store in C
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      c[i][j] = 0;
      for (int k = 0; k < col; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Print Matrix C
  printf("\nMatrix C = A * B:\n");
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}