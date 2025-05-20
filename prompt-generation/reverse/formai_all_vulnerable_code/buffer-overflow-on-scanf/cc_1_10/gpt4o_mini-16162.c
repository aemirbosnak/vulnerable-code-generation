//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2], int result[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1 = 2, cols1 = 2;          
    int rows2 = 2, cols2 = 2;          
    int mat1[rows1][cols1];            
    int mat2[rows2][cols2];            
    int resultAdd[rows1][cols1];      
    int resultSub[rows1][cols1];      
    int resultMul[rows1][cols2];      

    printf("Enter values for the first matrix (%d x %d):\n", rows1, cols1);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter values for the second matrix (%d x %d):\n", rows2, cols2);
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    printMatrix(rows1, cols1, mat1);
    
    printf("Matrix B:\n");
    printMatrix(rows2, cols2, mat2);
    
    printf("Adding Matrices:\n");
    addMatrices(rows1, cols1, mat1, mat2, resultAdd);
    printMatrix(rows1, cols1, resultAdd);
    
    printf("Subtracting Matrices:\n");
    subtractMatrices(rows1, cols1, mat1, mat2, resultSub);
    printMatrix(rows1, cols1, resultSub);

    printf("Multiplying Matrices:\n");
    multiplyMatrices(rows1, cols1, mat1, rows2, cols2, mat2, resultMul);
    printMatrix(rows1, cols2, resultMul);

    return 0;
}