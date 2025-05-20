//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matrix operations module
void matrix_ops(int** mat, int rows, int cols, int operation) {
    // Perform matrix operation
    switch (operation) {
        case 1: // Addition
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    mat[i][j] += mat[i][j];
                }
            }
            break;
        case 2: // Subtraction
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    mat[i][j] -= mat[i][j];
                }
            }
            break;
        case 3: // Multiplication
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    mat[i][j] *= mat[i][j];
                }
            }
            break;
        case 4: // Transpose
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int temp = mat[j][i];
                    mat[j][i] = mat[i][j];
                    mat[i][j] = temp;
                }
            }
            break;
        default:
            printf("Invalid operation\n");
            return;
    }
}

int main() {
    int rows1 = 3, cols1 = 3, rows2 = 3, cols2 = 3;
    int** mat1 = malloc(rows1 * sizeof(int *));
    int** mat2 = malloc(rows2 * sizeof(int *));

    // Initialize matrix 1
    for (int i = 0; i < rows1; i++) {
        mat1[i] = malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            mat1[i][j] = i * j;
        }
    }

    // Initialize matrix 2
    for (int i = 0; i < rows2; i++) {
        mat2[i] = malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            mat2[i][j] = i * j + 1;
        }
    }

    // Perform matrix operations
    matrix_ops(mat1, rows1, cols1, 1); // Addition
    matrix_ops(mat1, rows1, cols1, 2); // Subtraction
    matrix_ops(mat1, rows1, cols1, 3); // Multiplication
    matrix_ops(mat1, rows1, cols1, 4); // Transpose

    // Print matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    return 0;
}