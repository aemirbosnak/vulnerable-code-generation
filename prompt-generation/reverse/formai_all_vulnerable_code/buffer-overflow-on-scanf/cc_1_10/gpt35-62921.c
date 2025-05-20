//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int **matrix1, int **matrix2, int size) {
    int **result = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        result[i] = (int *) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("\nSum of the matrices: \n");
    printMatrix(result, size);
    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);
}

// Function to subtract two matrices
void subtractMatrices(int **matrix1, int **matrix2, int size) {
    int **result = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        result[i] = (int *) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("\nDifference of the matrices: \n");
    printMatrix(result, size);
    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);
}

// Function to multiply two matrices
void multiplyMatrices(int **matrix1, int **matrix2, int size) {
    int **result = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        result[i] = (int *) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("\nMultiplication of the matrices: \n");
    printMatrix(result, size);
    for (int i = 0; i < size; i++) {
        free(result[i]);
    }
    free(result);
}

int main() {
    int size;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);
    printf("Enter the first matrix:\n");
    int **matrix1 = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix1[i] = (int *) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the second matrix:\n");
    int **matrix2 = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix2[i] = (int *) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("\nMatrix 1: \n");
    printMatrix(matrix1, size);
    printf("\nMatrix 2: \n");
    printMatrix(matrix2, size);
    addMatrices(matrix1, matrix2, size);
    subtractMatrices(matrix1, matrix2, size);
    multiplyMatrices(matrix1, matrix2, size);
    for (int i = 0; i < size; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    return 0;
}