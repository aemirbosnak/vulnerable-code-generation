//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, m, p, q, i, j, k, sum = 0;
  int **a, **b, **c;

  printf("Enter the number of rows and columns of matrix A: ");
  scanf("%d %d", &n, &m);

  printf("Enter the number of rows and columns of matrix B: ");
  scanf("%d %d", &p, &q);

  if (m != p) {
    printf("Matrices cannot be multiplied.\n");
    return 1;
  }

  a = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    a[i] = (int *)malloc(m * sizeof(int));
  }

  b = (int **)malloc(p * sizeof(int *));
  for (i = 0; i < p; i++) {
    b[i] = (int *)malloc(q * sizeof(int));
  }

  c = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    c[i] = (int *)malloc(q * sizeof(int));
  }

  printf("Enter the elements of matrix A:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of matrix B:\n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < q; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < q; j++) {
      sum = 0;
      for (k = 0; k < m; k++) {
        sum += a[i][k] * b[k][j];
      }
      c[i][j] = sum;
    }
  }

  printf("The product of matrices A and B is:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < q; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);

  for (i = 0; i < p; i++) {
    free(b[i]);
  }
  free(b);

  for (i = 0; i < n; i++) {
    free(c[i]);
  }
  free(c);

  return 0;
}