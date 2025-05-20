//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a few constants to make our lives easier
#define ROWS 3
#define COLS 3

// Define some helper functions for printing matrices and getting input
void printMatrix(int matrix[ROWS][COLS]);
void getMatrixInput(int matrix[ROWS][COLS]);

int main() {

  printf("\n\n\n*************** Welcome to the Matrix Operation Bot *****************\n\n");
  printf("I'm here to help you perform some basic matrix operations! Let's get started.\n");

  int matrixA[ROWS][COLS], matrixB[ROWS][COLS], matrixC[ROWS][COLS];

  printf("\nFirst, let's create two matrices. Enter the values for the first matrix:\n");
  getMatrixInput(matrixA);
  printf("\nGreat! Now enter the values for the second matrix:\n");
  getMatrixInput(matrixB);

  // Add the two matrices together
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }

  printf("\nLet's see what happens when we add these two matrices together:\n\n");
  printMatrix(matrixA);
  printf("+\n");
  printMatrix(matrixB);
  printf("=\n");
  printMatrix(matrixC);

  // Multiply the two matrices together
  printf("\nNow, let's multiply these matrices together:\n\n");
  int sum;
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      sum = 0;
      for(int k = 0; k < ROWS; k++) {
        sum += matrixA[i][k] * matrixB[k][j];
      }
      matrixC[i][j] = sum;
    }
  }

  printf("\nHere's the result of multiplying these matrices:\n\n");
  printMatrix(matrixA);
  printf("*\n");
  printMatrix(matrixB);
  printf("=\n");
  printMatrix(matrixC);

  // Determine whether the matrices are equal
  printf("\nFinally, let's determine whether these two matrices are equal:\n\n");

  int equal = 1;
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      if(matrixA[i][j] != matrixB[i][j]) {
        equal = 0;
        break;
      }
    }
  }

  if(equal) {
    printf("The two matrices are equal!\n\n");
  } else {
    printf("The two matrices are not equal.\n\n");
  }

  printf("Thanks for using the Matrix Operation Bot. Have a great day!\n\n");

  return 0;
}

// Function to print a given matrix
void printMatrix(int matrix[ROWS][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to get input from the user for a matrix
void getMatrixInput(int matrix[ROWS][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("Enter a value for row %d, column %d: ", i+1, j+1);
      scanf("%d", &matrix[i][j]);
    }
  }
}