//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>

#define MAX_ROWS_COLS 5

// Function to print a given matrix
void print_matrix(int matrix[][MAX_ROWS_COLS], int rows, int cols) {
    printf("\nMatrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void add_matrices(int matrix1[][MAX_ROWS_COLS], int matrix2[][MAX_ROWS_COLS], int rows, int cols) {
    int result[MAX_ROWS_COLS][MAX_ROWS_COLS];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    print_matrix(result, rows, cols);
}

// Function to subtract two matrices
void subtract_matrices(int matrix1[][MAX_ROWS_COLS], int matrix2[][MAX_ROWS_COLS], int rows, int cols) {
    int result[MAX_ROWS_COLS][MAX_ROWS_COLS];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    print_matrix(result, rows, cols);
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[][MAX_ROWS_COLS], int matrix2[][MAX_ROWS_COLS], int rows1, int cols1, int cols2) {
    int result[MAX_ROWS_COLS][MAX_ROWS_COLS];
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            int sum = 0;
            for(int k=0; k<cols1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    print_matrix(result, rows1, cols2);
}

int main() {
    int matrix1[MAX_ROWS_COLS][MAX_ROWS_COLS], matrix2[MAX_ROWS_COLS][MAX_ROWS_COLS];
    int rows, cols;

    // Get input for the first matrix
    printf("Enter the number of rows and columns of the first matrix (maximum %d): ", MAX_ROWS_COLS);
    scanf("%d %d", &rows, &cols);
    printf("Enter the elements of the first matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Get input for the second matrix
    printf("\nEnter the number of rows and columns of the second matrix (maximum %d): ", MAX_ROWS_COLS);
    int rows2, cols2;
    scanf("%d %d", &rows2, &cols2);
    printf("Enter the elements of the second matrix:\n");
    for(int i=0; i<rows2; i++) {
        for(int j=0; j<cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform operations and print results
    printf("\nPerforming operations:\n");
    printf("\nMatrix1:");
    print_matrix(matrix1, rows, cols);
    printf("Matrix2:");
    print_matrix(matrix2, rows2, cols2);

    if(rows != rows2 || cols != cols2) {
        printf("\nError: Matrices cannot be added or subtracted.");
    }
    else {
        printf("\nAdding matrices:");
        add_matrices(matrix1, matrix2, rows, cols);
        printf("Subtracting matrices:");
        subtract_matrices(matrix1, matrix2, rows, cols);
    }

    if(cols != rows2) {
        printf("\nError: Matrices cannot be multiplied.");
    }
    else {
        printf("\nMultiplying matrices:");
        multiply_matrices(matrix1, matrix2, rows, cols, cols2);
    }

    return 0;
}