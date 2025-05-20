//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define the dimensions of the matrix
  int rows = 3, cols = 3;

  // Allocate memory for the matrix
  int *matrix = (int *)malloc(rows * cols * sizeof(int));

  // Initialize the matrix with random values
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i * cols + j] = rand() % 10;
    }
  }

  // Print the original matrix
  printf("Original matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i * cols + j]);
    }
    printf("\n");
  }

  // Transpose the matrix
  int *transposed = (int *)malloc(cols * rows * sizeof(int));
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      transposed[j * cols + i] = matrix[i * cols + j];
    }
  }

  // Print the transposed matrix
  printf("Transposed matrix:\n");
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%d ", transposed[i * rows + j]);
    }
    printf("\n");
  }

  // Multiply the original matrix by itself
  int *product = (int *)malloc(rows * rows * sizeof(int));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < cols; k++) {
        product[i * rows + j] += matrix[i * cols + k] * matrix[k * cols + j];
      }
    }
  }

  // Print the product of the original matrix
  printf("Product of the original matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%d ", product[i * rows + j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the matrices
  free(matrix);
  free(transposed);
  free(product);

  return 0;
}