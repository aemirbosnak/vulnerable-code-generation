//FormAI DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>

int main() {
  int a[3][3], b[3][3], c[3][3];
  int i, j, k;

  printf("Enter the elements of the first matrix:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("\nEnter the elements of the second matrix:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  printf("\nThe first matrix is:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("\nThe second matrix is:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      c[i][j] = 0;
      for (k = 0; k < 3; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  printf("\nThe result of matrix multiplication is:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}