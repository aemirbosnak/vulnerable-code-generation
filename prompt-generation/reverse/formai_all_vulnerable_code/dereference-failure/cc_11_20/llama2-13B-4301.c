//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matrix operations module
void matrix_operations(int **matrix, int rows, int cols, char op) {
    int i, j, k;

    // Check for invalid input
    if (rows < 1 || cols < 1 || !matrix) {
        printf("Invalid input\n");
        return;
    }

    // Perform matrix operation
    switch (op) {
        case '+':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < cols; k++) {
                        matrix[i][j] += matrix[i][k] * matrix[k][j];
                    }
                }
            }
            break;
        case '-':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < cols; k++) {
                        matrix[i][j] -= matrix[i][k] * matrix[k][j];
                    }
                }
            }
            break;
        case '*':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < cols; k++) {
                        matrix[i][j] *= matrix[i][k] * matrix[k][j];
                    }
                }
            }
            break;
        case '/':
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < cols; k++) {
                        matrix[i][j] /= matrix[i][k] * matrix[k][j];
                    }
                }
            }
            break;
        default:
            printf("Invalid operation\n");
            return;
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    int **matrix1, **matrix2;

    // Get matrix dimensions
    printf("Enter the dimensions of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the dimensions of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Allocate memory for the matrices
    matrix1 = (int **)calloc(rows1, sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)calloc(cols1, sizeof(int));
    }

    matrix2 = (int **)calloc(rows2, sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)calloc(cols2, sizeof(int));
    }

    // Initialize the matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    // Perform matrix operations
    char op;
    do {
        printf("Enter the operation (+, -, *, /): ");
        scanf(" %c", &op);

        matrix_operations(matrix1, rows1, cols1, op);
        matrix_operations(matrix2, rows2, cols2, op);
    } while (op != 'q');

    // Print the result
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    return 0;
}