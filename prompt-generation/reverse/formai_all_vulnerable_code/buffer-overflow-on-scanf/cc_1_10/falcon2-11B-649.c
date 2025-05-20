//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
int addMatrices(int **matrix1, int **matrix2, int m, int n) {
    int **result = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to multiply a matrix by a scalar
void multiplyMatrix(int **matrix, int *scalar, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] *= scalar[i];
        }
    }
}

// Function to transpose a matrix
int **transposeMatrix(int **matrix, int m, int n) {
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}

// Function to calculate the determinant of a square matrix
int calculateDeterminant(int **matrix, int m) {
    if (m == 1) {
        return matrix[0][0];
    }

    int **minor = (int **)malloc(m * sizeof(int *));
    int *coefficient = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        minor[i] = transposeMatrix(matrix, m, m);
        multiplyMatrix(minor[i], &coefficient[i], m, m);
    }

    int determinant = 1;
    for (int i = 0; i < m; i++) {
        determinant *= coefficient[i];
    }

    free(minor);
    free(coefficient);

    return determinant;
}

int main() {
    int m, n;
    printf("Enter the size of the first matrix: ");
    scanf("%d", &m);
    printf("Enter the size of the second matrix: ");
    scanf("%d", &n);

    int **matrix1 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
    }

    int **matrix2 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix2[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int **result = addMatrices(matrix1, matrix2, m, n);
    printf("The sum of the matrices is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    free(result);
    free(matrix1);
    free(matrix2);

    return 0;
}