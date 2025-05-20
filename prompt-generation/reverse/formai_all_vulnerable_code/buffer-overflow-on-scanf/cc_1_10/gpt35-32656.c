//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to print the matrix
void print_matrix(int matrix[][MAX_SIZE], int rows, int cols) {
    printf("Printing matrix...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    printf("Adding matrices...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    printf("Subtracting matrices...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[][MAX_SIZE], int cols1, int rows2, int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int rows1, int cols2) {
    printf("Multiplying matrices...\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < rows2; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows1, rows2, cols1, cols2;
    
    printf("Enter the number of rows and columns for matrix 1: \n");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the elements of matrix 1: \n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("Enter the number of rows and columns for matrix 2: \n");
    scanf("%d %d", &rows2, &cols2);
    printf("Enter the elements of matrix 2: \n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    if (cols1 != rows2) {
        printf("Error: The number of columns in matrix 1 must match the number of rows in matrix 2.\n");
        exit(1);
    }
    
    int choice;
    printf("Select an operation to perform:\n");
    printf("1. Add matrices\n");
    printf("2. Subtract matrices\n");
    printf("3. Multiply matrices\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            add_matrices(matrix1, matrix2, result, rows1, cols1);
            print_matrix(result, rows1, cols1);
            break;
        case 2:
            subtract_matrices(matrix1, matrix2, result, rows1, cols1);
            print_matrix(result, rows1, cols1);
            break;
        case 3:
            multiply_matrices(matrix1, cols1, rows2, matrix2, result, rows1, cols2);
            print_matrix(result, rows1, cols2);
            break;
        default:
            printf("Error: Invalid choice.\n");
            exit(1);
    }
    
    return 0;
}