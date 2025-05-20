//FormAI DATASET v1.0 Category: Matrix operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to print matrices
void printMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, rows2, columns1, columns2;

    // Get number of rows and columns for matrices
    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &columns1);
    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &columns2);

    // Check if matrices can be multiplied
    if (columns1 != rows2) {
        printf("Error: Cannot multiply matrices. Number of columns in first matrix must be equal to number of rows in second matrix.\n");
        return 0;
    }

    // Create dynamic memory for matrices
    int** matrix1 = (int**) malloc(rows1 * sizeof(int*));
    int** matrix2 = (int**) malloc(rows2 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int*) malloc(columns1 * sizeof(int));
    }
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int*) malloc(columns2 * sizeof(int));
    }

    // Get values for matrices
    printf("Enter values for first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter values for second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Create dynamic memory for resultant matrix
    int** result = (int**) malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int*) malloc(columns2 * sizeof(int));
    }

    // Multiply matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            for (int k = 0; k < rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print matrices and resultant matrix
    printf("First Matrix:\n");
    printMatrix(matrix1, rows1, columns1);
    printf("\nSecond Matrix:\n");
    printMatrix(matrix2, rows2, columns2);
    printf("\nResultant Matrix:\n");
    printMatrix(result, rows1, columns2);

    // Free allocated memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}