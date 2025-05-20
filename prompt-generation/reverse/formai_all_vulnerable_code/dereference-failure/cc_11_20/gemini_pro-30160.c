//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int m, n, p;
  printf("Enter the number of rows and columns of the first matrix: ");
  scanf("%d%d", &m, &n);
  int **a = malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    a[i] = malloc(n * sizeof(int));
  }
  printf("Enter the elements of the first matrix:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  printf("Enter the number of rows and columns of the second matrix: ");
  scanf("%d%d", &m, &p);
  int **b = malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    b[i] = malloc(p * sizeof(int));
  }
  printf("Enter the elements of the second matrix:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  int **c = malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    c[i] = malloc(p * sizeof(int));
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      c[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  printf("The product of the two matrices is:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < m; i++) {
    free(a[i]);
  }
  free(a);
  for (int i = 0; i < m; i++) {
    free(b[i]);
  }
  free(b);
  for (int i = 0; i < m; i++) {
    free(c[i]);
  }
  free(c);
  return 0;
}