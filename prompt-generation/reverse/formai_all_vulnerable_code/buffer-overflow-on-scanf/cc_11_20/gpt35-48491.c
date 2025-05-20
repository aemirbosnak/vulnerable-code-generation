//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>

int main() {
  int row, col, i, j;

  printf("Enter number of rows for matrix: ");
  scanf("%d", &row);

  printf("Enter number of columns for matrix: ");
  scanf("%d", &col);

  int matrix_A[row][col], matrix_B[row][col], matrix_C[row][col], matrix_D[row][col];

  printf("\nEnter Matrix A:\n");

  // Input Matrix A
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      scanf("%d", &matrix_A[i][j]);
    }
  }

  printf("\nEnter Matrix B:\n");

  // Input Matrix B
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      scanf("%d", &matrix_B[i][j]);
    }
  }

  // Add matrix A and B and output the result in matrix C
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
    }
  }

  // Multiply matrix A and B and output the result in matrix D
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      matrix_D[i][j] = 0;
      for(int k=0; k<col; k++){
        matrix_D[i][j] += matrix_A[i][k] * matrix_B[k][j];
      }
    }
  }

  // Display the results
  printf("\nMatrix A:\n");
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      printf("%d ", matrix_A[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix B:\n");
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      printf("%d ", matrix_B[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix A + B:\n");
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      printf("%d ", matrix_C[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix A * B:\n");
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      printf("%d ", matrix_D[i][j]);
    }
    printf("\n");
  }

  return 0;
}