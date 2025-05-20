//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>

int main() {
  int A[10][10], B[10][10], C[10][10], i, j, k, m, n, p, q;
  printf("Enter the order of matrix A: ");
  scanf("%d %d",&m,&n);
  printf("Enter the elements of matrix A:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d",&A[i][j]);
    }
  }
  printf("Enter the order of matrix B: ");
  scanf("%d %d",&p,&q);
  printf("Enter the elements of matrix B:\n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < q; j++) {
      scanf("%d",&B[i][j]);
    }
  }
  if (n != p) {
    printf("Error: Invalid matrix order.\n");
    return 0;
  }
 
  // Matrix Addition
  printf("The sum of matrices A and B is:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j] = A[i][j] + B[i][j];
      printf("%d ",C[i][j]);
    }
    printf("\n");
  }
 
  // Matrix Subtraction
  printf("The difference of matrices A and B is:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i][j] = A[i][j] - B[i][j];
      printf("%d ",C[i][j]);
    }
    printf("\n");
  }
 
  // Matrix Multiplication
  printf("The product of matrices A and B is:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < q; j++) {
      C[i][j] = 0;
      for (k = 0; k < n; k++) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
      }
      printf("%d ",C[i][j]);
    }
    printf("\n");
  }
 
  // Matrix Transpose
  printf("The transpose of matrix A is:\n");
  for (j = 0; j < n; j++) {
    for (i = 0; i < m; i++) {
      printf("%d ",A[i][j]);
    }
    printf("\n");
  }
 
  return 0;
}