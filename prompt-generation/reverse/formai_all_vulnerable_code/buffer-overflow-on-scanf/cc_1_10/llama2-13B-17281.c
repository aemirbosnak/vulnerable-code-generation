//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to transpose a matrix
void transpose(float *matrix, int rows, int cols) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            for (k = 0; k < rows; k++) {
                matrix[i * cols + j] = matrix[k * rows + j];
            }
        }
    }
}

// Function to swap two matrices
void swap_matrices(float *matrix1, float *matrix2, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            float temp = matrix1[i * cols + j];
            matrix1[i * cols + j] = matrix2[i * cols + j];
            matrix2[i * cols + j] = temp;
        }
    }
}

// Function to rotate a matrix by 90 degrees clockwise
void rotate_matrix(float *matrix, int rows, int cols) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            float temp = matrix[i * cols + j];
            matrix[i * cols + j] = matrix[((i * cols + j) % rows) % rows];
            matrix[((i * cols + j) % rows)] = temp;
        }
    }
}

int main() {
    int rows, cols;
    float *matrix;

    // Initialize matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    matrix = (float *)malloc(rows * cols * sizeof(float));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element %d, %d: ", i, j);
            scanf("%f", &matrix[i * cols + j]);
        }
    }

    // Transpose the matrix
    transpose(matrix, rows, cols);

    // Swap the matrix with its transpose
    swap_matrices(matrix, matrix, rows, cols);

    // Rotate the matrix by 90 degrees clockwise
    rotate_matrix(matrix, rows, cols);

    // Print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}