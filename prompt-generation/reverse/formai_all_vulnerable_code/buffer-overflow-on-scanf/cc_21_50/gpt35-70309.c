//FormAI DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>

// A peaceful program to perform basic matrix operations

int main() {
  int a[10][10], b[10][10], result[10][10];
  int i, j, k, m, n, p, q;

  printf("Enter the number of rows and columns for the first matrix: ");
  scanf("%d %d", &m, &n);

  printf("Enter the elements of the first matrix: \n");
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      scanf("%d", &a[i][j]);

  printf("Enter the number of rows and columns for the second matrix: ");
  scanf("%d %d", &p, &q);

  if(n != p) {
    printf("Matrix multiplication is not possible. The number of columns in the first matrix should be equal to the number of rows in the second matrix.\n");
    return 0;
  }

  printf("Enter the elements of the second matrix: \n");
  for(i = 0; i < p; i++)
    for(j = 0; j < q; j++)
      scanf("%d", &b[i][j]);

  // Multiplication of two matrices
  for(i = 0; i < m; ++i) {
    for(j = 0; j < q; ++j) {
      result[i][j] = 0;
      for(k = 0; k < n; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Displaying the resultant matrix
  printf("The resultant matrix after multiplication is: \n");
  for(i = 0; i < m; ++i) {
    for(j = 0; j < q; ++j) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Addition of two matrices
  if(m == p && n == q) {
    printf("The sum of the two matrices is: \n");
    for(i = 0; i < m; ++i) {
      for(j = 0; j < n; ++j) {
        printf("%d ", a[i][j] + b[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("Matrix addition is not possible. The sizes of both matrices should be the same.\n");
  }

  // Subtraction of two matrices
  if(m == p && n == q) {
    printf("The subtraction of the two matrices is: \n");
    for(i = 0; i < m; ++i) {
      for(j = 0; j < n; ++j) {
        printf("%d ", a[i][j] - b[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("Matrix subtraction is not possible. The sizes of both matrices should be the same.\n");
  }

  // Transpose of the first matrix
  printf("The transpose of the first matrix is: \n");
  for(i = 0; i < m; ++i) {
    for(j = 0; j < n; ++j) {
      printf("%d ", a[j][i]);
    }
    printf("\n");
  }

  return 0;
}