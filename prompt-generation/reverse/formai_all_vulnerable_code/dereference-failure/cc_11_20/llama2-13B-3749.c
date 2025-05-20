//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matrix operations module
void matrix_ops(int **mat, int rows, int cols, char *op) {
    int i, j, k;
    switch (op[0]) {
        case '+':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < rows; k++) {
                        mat[i][j] += mat[i][k] * mat[k][j];
                    }
                }
            }
            break;
        case '-':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < rows; k++) {
                        mat[i][j] -= mat[i][k] * mat[k][j];
                    }
                }
            }
            break;
        case '*':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < rows; k++) {
                        mat[i][j] *= mat[i][k] * mat[k][j];
                    }
                }
            }
            break;
        case '/':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < rows; k++) {
                        if (mat[i][j] != 0) {
                            mat[i][j] /= mat[i][k] * mat[k][j];
                        }
                    }
                }
            }
            break;
        default:
            printf("Invalid operation\n");
            return;
    }
    printf("Matrix operations completed\n");
}

int main() {
    int rows, cols;
    int **mat;

    // Get matrix size from user
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    // Allocate memory for matrix
    mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }

    // Set matrix elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element %d, %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Perform matrix operations
    char op[10];
    printf("Enter the operation to perform (+, -, *, /): ");
    scanf("%s", op);
    matrix_ops(mat, rows, cols, op);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}