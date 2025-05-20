//FormAI DATASET v1.0 Category: Matrix operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

void addMatrix(int matrix1[][LIMIT], int matrix2[][LIMIT], int result[][LIMIT], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrix(int matrix1[][LIMIT], int matrix2[][LIMIT], int result[][LIMIT], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrix(int matrix1[][LIMIT], int matrix2[][LIMIT], int result[][LIMIT], int row1, int col1, int row2, int col2) {
    if(col1 != row2) {
        printf("Error: Invalid matrix dimensions\n");
        exit(0);
    }
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][LIMIT], int transpose[][LIMIT], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[][LIMIT], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[LIMIT][LIMIT], matrix2[LIMIT][LIMIT], result[LIMIT][LIMIT];
    int row1, col1, row2, col2;
    printf("Enter matrix 1 dimensions (row x col): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter matrix 1: \n");
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter matrix 2 dimensions (row x col): ");
    scanf("%d %d", &row2, &col2);
    printf("Enter matrix 2: \n");
    for(int i = 0; i < row2; i++) {
        for(int j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("\nMatrix 1:\n");
    displayMatrix(matrix1, row1, col1);
    printf("\nMatrix 2:\n");
    displayMatrix(matrix2, row2, col2);
    if(row1 == row2 && col1 == col2) {
        addMatrix(matrix1, matrix2, result, row1, col1);
        printf("\nMatrix 1 + Matrix 2:\n");
        displayMatrix(result, row1, col1);
        subtractMatrix(matrix1, matrix2, result, row1, col1);
        printf("\nMatrix 1 - Matrix 2:\n");
        displayMatrix(result, row1, col1);
    }
    if(col1 == row2) {
        multiplyMatrix(matrix1, matrix2, result, row1, col1, row2, col2);
        printf("\nMatrix 1 * Matrix 2:\n");
        displayMatrix(result, row1, col2);
    }
    printf("\nTranspose of Matrix 1:\n");
    int transpose[LIMIT][LIMIT];
    transposeMatrix(matrix1, transpose, row1, col1);
    displayMatrix(transpose, col1, row1);
    return 0;
}