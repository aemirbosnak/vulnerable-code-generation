//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

// Function to create a matrix
void createMatrix(int mat[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("Enter element (%d, %d): ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int mat[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[][COL], int mat2[][COL], int res[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int mat1[][COL], int mat2[][COL], int res[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[][COL], int mat2[][COL], int res[][COL]) {
    int i, j, k;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            res[i][j] = 0;
            for (k = 0; k < COL; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[ROW][COL], mat2[ROW][COL], res[ROW][COL];

    // Create matrices
    createMatrix(mat1);
    createMatrix(mat2);

    // Print matrices
    printf("Matrix 1:\n");
    printMatrix(mat1);
    printf("Matrix 2:\n");
    printMatrix(mat2);

    // Add matrices
    addMatrices(mat1, mat2, res);
    printf("Result of addition:\n");
    printMatrix(res);

    // Subtract matrices
    subtractMatrices(mat1, mat2, res);
    printf("Result of subtraction:\n");
    printMatrix(res);

    // Multiply matrices
    multiplyMatrices(mat1, mat2, res);
    printf("Result of multiplication:\n");
    printMatrix(res);

    return 0;
}