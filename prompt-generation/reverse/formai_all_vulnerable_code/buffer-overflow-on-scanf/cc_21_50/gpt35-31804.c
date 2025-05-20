//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows, cols, i, j;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  int first[rows][cols], second[rows][cols], result[rows][cols];

  printf("\nEnter the elements of the first matrix:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &first[i][j]);
    }
  }

  printf("\nEnter the elements of the second matrix:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &second[i][j]);
    }
  }

  //Addition
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      result[i][j] = first[i][j] + second[i][j];
    }
  }

  printf("\nAddition of the two matrices is:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  //Subtraction
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      result[i][j] = first[i][j] - second[i][j];
    }
  }

  printf("\nSubtraction of the two matrices is:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  //Multiplication
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      result[i][j] = 0;
    }
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      for (int k = 0; k < cols; k++) {
        result[i][j] += first[i][k] * second[k][j];
      }
    }
  }

  printf("\nMultiplication of the two matrices is:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  //Transpose of first matrix
  printf("\nTranspose of the first matrix is:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d\t", first[j][i]);
    }
    printf("\n");
  }

  return 0;
}