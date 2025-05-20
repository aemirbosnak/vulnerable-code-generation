//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the matrices
#define MAX_SIZE 10

// Define the types of operations that can be performed
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3

// Define the error messages
#define INVALID_SIZE "Invalid matrix size"
#define INVALID_OPERATION "Invalid operation"

// Define the function to get the size of the matrices
int get_size() {
  int size;
  printf("Enter the size of the matrices (1-%d): ", MAX_SIZE);
  scanf("%d", &size);
  if (size < 1 || size > MAX_SIZE) {
    printf("%s\n", INVALID_SIZE);
    exit(EXIT_FAILURE);
  }
  return size;
}

// Define the function to get the operation to be performed
int get_operation() {
  int operation;
  printf("Enter the operation to be performed (1-Addition, 2-Subtraction, 3-Multiplication): ");
  scanf("%d", &operation);
  if (operation < 1 || operation > 3) {
    printf("%s\n", INVALID_OPERATION);
    exit(EXIT_FAILURE);
  }
  return operation;
}

// Define the function to get the elements of the matrices
void get_elements(int size, int matrix[size][size]) {
  printf("Enter the elements of the first matrix:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("Enter the elements of the second matrix:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

// Define the function to add two matrices
void add_matrices(int size, int matrix1[size][size], int matrix2[size][size], int result[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

// Define the function to subtract two matrices
void subtract_matrices(int size, int matrix1[size][size], int matrix2[size][size], int result[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

// Define the function to multiply two matrices
void multiply_matrices(int size, int matrix1[size][size], int matrix2[size][size], int result[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result[i][j] = 0;
      for (int k = 0; k < size; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

// Define the function to print the result matrix
void print_result(int size, int result[size][size]) {
  printf("The result matrix is:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
}

// Define the main function
int main() {
  // Get the size of the matrices
  int size = get_size();

  // Get the operation to be performed
  int operation = get_operation();

  // Get the elements of the matrices
  int matrix1[size][size], matrix2[size][size], result[size][size];
  get_elements(size, matrix1);
  get_elements(size, matrix2);

  // Perform the operation on the matrices
  switch (operation) {
    case ADDITION:
      add_matrices(size, matrix1, matrix2, result);
      break;
    case SUBTRACTION:
      subtract_matrices(size, matrix1, matrix2, result);
      break;
    case MULTIPLICATION:
      multiply_matrices(size, matrix1, matrix2, result);
      break;
  }

  // Print the result matrix
  print_result(size, result);

  return 0;
}