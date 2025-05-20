//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int m, n, i, j;
  int **a, **b, **c;

  printf("Enter number of rows and columns of matrix: ");
  scanf("%d%d", &m, &n);

  a = (int **)calloc(m, sizeof(int *));
  b = (int **)calloc(m, sizeof(int *));
  c = (int **)calloc(m, sizeof(int *));
  for (i = 0; i < m; i++) {
    a[i] = (int *)calloc(n, sizeof(int));
    b[i] = (int *)calloc(n, sizeof(int));
    c[i] = (int *)calloc(n, sizeof(int));
  }

  printf("Enter matrix 1 elements:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter matrix 2 elements:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  printf("Matrix addition:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = a[i][j] + b[i][j];
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  printf("Matrix multiplication:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = 0;
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  printf("Matrix transpose:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = a[j][i];
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < m; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);

  return 0;
}