//FormAI DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>

void printMatrix(int matrix[][100], int rows, int columns) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[][100], int matrix2[][100], int resultMatrix[][100], int rows, int columns) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][100], int matrix2[][100], int resultMatrix[][100], int rows, int columns) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][100], int matrix2[][100], int resultMatrix[][100], int rows1, int columns1, int rows2, int columns2) {
    int i, j, k;
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < columns2; j++) {
            resultMatrix[i][j] = 0;
        }
    }

    for(i = 0; i < rows1; i++) {
        for(j = 0; j < columns2; j++) {
            for(k = 0; k < columns1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[100][100], matrix2[100][100], resultMatrix[100][100], rows1, columns1, rows2, columns2;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &columns1);

    printf("Enter the elements of the first matrix: ");
    int i, j;
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < columns1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &columns2);

    if(columns1 != rows2) {
        printf("Matrices cannot be multiplied!");
        return 0;
    }

    printf("Enter the elements of the second matrix: ");
    for(i = 0; i < rows2; i++) {
        for(j = 0; j < columns2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    printMatrix(matrix1, rows1, columns1);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, rows2, columns2);

    addMatrices(matrix1, matrix2, resultMatrix, rows1, columns1);
    printf("\nAddition of matrices:\n");
    printMatrix(resultMatrix, rows1, columns1);

    subtractMatrices(matrix1, matrix2, resultMatrix, rows1, columns1);
    printf("\nSubtraction of matrices:\n");
    printMatrix(resultMatrix, rows1, columns1);

    multiplyMatrices(matrix1, matrix2, resultMatrix, rows1, columns1, rows2, columns2);
    printf("\nMultiplication of matrices:\n");
    printMatrix(resultMatrix, rows1, columns2);

    return 0;
}