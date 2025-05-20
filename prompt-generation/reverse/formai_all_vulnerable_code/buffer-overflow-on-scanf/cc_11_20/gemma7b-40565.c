//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>

int main() {
  int n, m, i, j, x, y, z, a[10][10], b[10][10], c[10][10], d[10][10], e[10][10];

  printf("Enter the dimensions of the matrices:");
  scanf("%d %d", &n, &m);

  printf("Enter the elements of matrix A:");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of matrix B:");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  // Matrix addition
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  // Matrix subtraction
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      d[i][j] = a[i][j] - b[i][j];
    }
  }

  // Matrix multiplication
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      e[i][j] = 0;
      for (z = 0; z < m; z++) {
        e[i][j] += a[i][z] * b[z][j];
      }
    }
  }

  // Print the results
  printf("The sum of the matrices is:");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  printf("The difference of the matrices is:");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }

  printf("The product of the matrices is:");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", e[i][j]);
    }
    printf("\n");
  }

  return 0;
}