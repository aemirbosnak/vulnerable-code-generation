//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int m, n, o, p, i, j, k, l;
  int **a, **b, **c;

  printf("Enter the number of rows and columns of matrix A: ");
  scanf("%d %d", &m, &n);

  printf("Enter the elements of matrix A:\n");
  a = (int **)malloc(m * sizeof(int *));
  for (i = 0; i < m; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the number of rows and columns of matrix B: ");
  scanf("%d %d", &o, &p);

  if (n != o) {
    printf("Matrix multiplication is not possible.\n");
    return 0;
  }

  printf("Enter the elements of matrix B:\n");
  b = (int **)malloc(o * sizeof(int *));
  for (i = 0; i < o; i++) {
    b[i] = (int *)malloc(p * sizeof(int));
    for (j = 0; j < p; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  c = (int **)malloc(m * sizeof(int *));
  for (i = 0; i < m; i++) {
    c[i] = (int *)malloc(p * sizeof(int));
    for (j = 0; j < p; j++) {
      c[i][j] = 0;
      for (k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  printf("The product of the two matrices is:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < p; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}