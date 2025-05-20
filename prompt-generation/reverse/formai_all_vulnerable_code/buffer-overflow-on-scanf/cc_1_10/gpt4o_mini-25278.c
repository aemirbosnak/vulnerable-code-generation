//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure for representing a matrix
typedef struct Matrix {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

// Function to initialize a matrix
void init_matrix(Matrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

// Function to display a matrix
void display_matrix(Matrix matrix) {
    printf("The matrix is:\n");
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
Matrix add_matrices(Matrix m1, Matrix m2) {
    Matrix result;
    result.rows = m1.rows;
    result.cols = m1.cols;
    
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

// Function for matrix multiplication
Matrix multiply_matrices(Matrix m1, Matrix m2) {
    Matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result.data[i][j] = 0; // Start with zero for sum
            for (int k = 0; k < m1.cols; k++) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return result;
}

int main() {
    Matrix romeo, juliet, result;
    int choice;

    printf("Enter the dimensions of Romeo's matrix (rows cols): ");
    int r_rows, r_cols;
    scanf("%d %d", &r_rows, &r_cols);
    init_matrix(&romeo, r_rows, r_cols);

    printf("Enter the dimensions of Juliet's matrix (rows cols): ");
    int j_rows, j_cols;
    scanf("%d %d", &j_rows, &j_cols);
    init_matrix(&juliet, j_rows, j_cols);

    printf("Choose an operation:\n1. Add matrices\n2. Multiply matrices\n-> ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (romeo.rows != juliet.rows || romeo.cols != juliet.cols) {
            printf("Alas! The matrices must be of same size to add them.\n");
            return -1;
        }
        result = add_matrices(romeo, juliet);
        display_matrix(result);
    } else if (choice == 2) {
        if (romeo.cols != juliet.rows) {
            printf("Oh no! The matrices cannot be multiplied. Check the dimensions.\n");
            return -1;
        }
        result = multiply_matrices(romeo, juliet);
        display_matrix(result);
    } else {
        printf("What a tragic choice! Please choose a valid operation.\n");
    }

    return 0;
}