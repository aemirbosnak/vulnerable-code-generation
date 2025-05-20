//FormAI DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
  int matrix[3][3];
  int i, j, sum = 0, max = 0;

  // taking input for the matrix
  printf("Enter elements of the 3x3 matrix:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("Enter element[%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }

  // printing the matrix
  printf("\nThe matrix is:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // calculating sum of diagonal elements
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (i == j) {
        sum += matrix[i][j];
      }
    }
  }
  printf("\nSum of diagonal elements: %d\n", sum);

  // calculating maximum element in the matrix
  max = matrix[0][0];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (matrix[i][j] > max) {
        max = matrix[i][j];
      }
    }
  }
  printf("\nMaximum element in the matrix: %d\n", max);

  // finding transpose of the matrix
  int transpose[3][3];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      transpose[j][i] = matrix[i][j];
    }
  }
  printf("\nTranspose of the matrix is:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }

  // multiplying matrix by a scalar value
  int scalar = 2;
  printf("\nMatrix multiplied by scalar %d is:\n", scalar);
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j] * scalar);
    }
    printf("\n");
  }

  return 0;
}