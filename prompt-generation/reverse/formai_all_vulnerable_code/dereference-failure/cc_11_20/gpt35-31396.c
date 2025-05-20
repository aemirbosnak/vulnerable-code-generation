//FormAI DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {

  int row1, col1, row2, col2, i, j;
  int **matrix1, **matrix2, **result;

  //reading matrix1 size from the user
  printf("Enter the number of rows and columns for matrix1: ");
  scanf("%d%d", &row1, &col1);

  //reading matrix2 size from user
  printf("Enter the number of rows and columns for matrix2: ");
  scanf("%d%d", &row2, &col2);

  //checking if matrix operations are possible or not
  if (col1 != row2) {
    printf("Matrix multiplication is not possible!\n");
    exit(0);
  }

  //allocating memory for matrix1
  matrix1 = (int **)malloc(row1 * sizeof(int *));
  for (i = 0; i < row1; i++) {
    matrix1[i] = (int *)malloc(col1 * sizeof(int));
  }

  //allocating memory for matrix2
  matrix2 = (int **)malloc(row2 * sizeof(int *));
  for (i = 0; i < row2; i++) {
    matrix2[i] = (int *)malloc(col2 * sizeof(int));
  }

  //allocating memory for result
  result = (int **)malloc(row1 * sizeof(int *));
  for (i = 0; i < row1; i++) {
    result[i] = (int *)malloc(col2 * sizeof(int));
  }

  //reading input for matrix1 from user
  printf("Enter the elements of matrix1:\n");
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col1; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }

  //reading input for matrix2 from user
  printf("Enter the elements of matrix2:\n");
  for (i = 0; i < row2; i++) {
    for (j = 0; j < col2; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }

  //performing matrix multiplication
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < col1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  //displaying the result
  printf("The result of matrix multiplication is:\n");
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  //deallocating the memory
  for (i = 0; i < row1; i++) {
    free(matrix1[i]);
  }
  free(matrix1);

  for (i = 0; i < row2; i++) {
    free(matrix2[i]);
  }
  free(matrix2);

  for (i = 0; i < row1; i++) {
    free(result[i]);
  }
  free(result);

  return 0;
}