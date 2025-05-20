//FormAI DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>

/* 
This program performs various matrix operations. 
We will ask the user for the size of the matrices 
and the elements in them. Then, we will add, subtract and multiply them. 
*/

int main() {

  int m, n, p, q, i, j, k, a[10][10], b[10][10], c[10][10];

  printf("Enter the number of rows in the first matrix: ");
  scanf("%d", &m);
  printf("Enter the number of columns in the first matrix: ");
  scanf("%d", &n);

  printf("Enter the elements of the first matrix:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the number of rows in the second matrix: ");
  scanf("%d", &p);
  printf("Enter the number of columns in the second matrix: ");
  scanf("%d", &q);

  if (n != p) {
    printf("Matrices cannot be multiplied!\n");
  } 
  else {

    printf("\nEnter the elements of the second matrix:\n");
    for (i = 0; i < p; i++) {
      for (j = 0; j < q; j++) {
        scanf("%d", &b[i][j]);
      }
    }

    // Multiply matrices
    for (i = 0; i < m; i++) {
      for (j = 0; j < q; j++) {
        c[i][j] = 0;
        for (k = 0; k < p; k++) {
          c[i][j] += a[i][k] * b[k][j];
        }
      }
    }

    // Print matrices
    printf("\nFirst matrix:\n");
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }

    printf("\nSecond matrix:\n");
    for (i = 0; i < p; i++) {
      for (j = 0; j < q; j++) {
        printf("%d ", b[i][j]);
      }
      printf("\n");
    }

    printf("\nProduct of the matrices:\n");
    for (i = 0; i < m; i++) {
      for (j = 0; j < q; j++) {
        printf("%d ", c[i][j]);
      }
      printf("\n");
    }

    // Add matrices
    printf("\nAddition of the matrices:\n");
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        printf("%d ", a[i][j] + b[i][j]);
      }
      printf("\n");
    }

    // Subtract matrices
    printf("\nSubtraction of the matrices:\n");
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        printf("%d ", a[i][j] - b[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}