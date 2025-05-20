//FormAI DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  int a[3][3], b[3][3], c[3][3], i, j;

  printf("Enter the elements of matrix A:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of matrix B:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  printf("\nMatrix A:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix B:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }

  // Matrix addition
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  printf("\nMatrix A + B:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Matrix subtraction
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      c[i][j] = a[i][j] - b[i][j];
    }
  }

  printf("\nMatrix A - B:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Matrix multiplication
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      c[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  printf("\nMatrix A * B:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}