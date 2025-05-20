//FormAI DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>

// Function to print the matrix
void print_matrix(int matrix[][100], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows1, int cols1, int rows2, int cols2) {
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[100][100], matrix2[100][100], result[100][100];
    int rows1, cols1, rows2, cols2;

    // Read input for matrix1
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter the elements of matrix 1:\n");
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    // Read input for matrix2
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    
    printf("Enter the elements of matrix 2:\n");
    for(int i = 0; i < rows2; i++) {
        for(int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Check if the matrices can be added or multiplied
    if(rows1 != rows2 || cols1 != cols2) {
        printf("Matrices cannot be added or multiplied!\n");
        return 1;
    }
    
    // Add the matrices and print the result
    add_matrices(matrix1, matrix2, result, rows1, cols1);
    printf("The sum of the matrices is:\n");
    print_matrix(result, rows1, cols1);
    
    // Multiply the matrices and print the result
    multiply_matrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
    printf("The product of the matrices is:\n");
    print_matrix(result, rows1, cols2);
    
    return 0;
}