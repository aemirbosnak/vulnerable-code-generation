//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 3

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int determinant(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  return (matrix[0][0] * matrix[1][1] * matrix[2][2]) +
         (matrix[0][1] * matrix[1][2] * matrix[2][0]) +
         (matrix[0][2] * matrix[1][0] * matrix[2][1]) -
         (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
         (matrix[0][0] * matrix[1][2] * matrix[2][1]) -
         (matrix[0][1] * matrix[1][0] * matrix[2][2]);
}

void addScalar(int scalar, int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      matrix[i][j] += scalar;
    }
  }
}

void subtractScalar(int scalar, int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      matrix[i][j] -= scalar;
    }
  }
}

void multiplyScalar(int scalar, int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      matrix[i][j] *= scalar;
    }
  }
}

void divideScalar(int scalar, int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  int i, j;
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      matrix[i][j] /= scalar;
    }
  }
}

void transpose(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  int i, j, temp;
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = i+1; j < MATRIX_SIZE; j++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

void randomFill(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
  int i, j;
  srand(time(NULL));
  for (i = 0; i < MATRIX_SIZE; i++) {
    for (j = 0; j < MATRIX_SIZE; j++) {
      matrix[i][j] = rand() % 10;
    }
  }
}

void surrealOperations() {
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  int scalar;

  printf("Let's create a matrix...\n");
  randomFill(matrix);
  printMatrix(matrix);

  printf("Let's find the determinant of the matrix...\n");
  printf("The determinant is %d\n", determinant(matrix));

  printf("Let's add a scalar to the matrix...\n");
  printf("Enter a scalar: ");
  scanf("%d", &scalar);
  addScalar(scalar, matrix);
  printMatrix(matrix);

  printf("Let's subtract a scalar from the matrix...\n");
  printf("Enter a scalar: ");
  scanf("%d", &scalar);
  subtractScalar(scalar, matrix);
  printMatrix(matrix);

  printf("Let's multiply the matrix by a scalar...\n");
  printf("Enter a scalar: ");
  scanf("%d", &scalar);
  multiplyScalar(scalar, matrix);
  printMatrix(matrix);

  printf("Let's divide the matrix by a scalar...\n");
  printf("Enter a scalar: ");
  scanf("%d", &scalar);
  divideScalar(scalar, matrix);
  printMatrix(matrix);

  printf("Let's transpose the matrix...\n");
  transpose(matrix);
  printMatrix(matrix);

  printf("Everything is surreal in this matrix world...\n");
}

int main() {
  surrealOperations();
  return 0;
}