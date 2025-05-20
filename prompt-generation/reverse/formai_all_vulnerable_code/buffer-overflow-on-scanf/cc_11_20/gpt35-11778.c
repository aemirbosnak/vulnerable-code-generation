//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int matrix1[3][3], matrix2[3][3], result[3][3];
  int i, j, k, sum;

  // Read the first matrix
  printf("Enter the elements of matrix1:\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }

  // Read the second matrix
  printf("Enter the elements of matrix2:\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }

  // Matrix addition
  printf("The result of matrix addition is:\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Matrix subtraction
  printf("The result of matrix subtraction is:\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Matrix multiplication
  printf("The result of matrix multiplication is:\n");
  for(i=0; i<3; i++) {
    for(j=0; j<3; j++) {
      sum = 0;
      for(k=0; k<3; k++) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      result[i][j] = sum;
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}