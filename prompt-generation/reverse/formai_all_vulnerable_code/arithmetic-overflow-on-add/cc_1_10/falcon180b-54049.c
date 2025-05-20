//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void generateMatrix(int matrix[][MAX_SIZE], int size);
void printMatrix(int matrix[][MAX_SIZE], int size);
void transposeMatrix(int matrix[][MAX_SIZE], int size);
void multiplyMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int size);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;

    printf("Matrix 1:\n");
    generateMatrix(matrix1, size);
    printMatrix(matrix1, size);

    printf("Matrix 2:\n");
    generateMatrix(matrix2, size);
    printMatrix(matrix2, size);

    printf("Multiplication of matrices:\n");
    multiplyMatrices(matrix1, matrix2, size);
    printMatrix(result, size);

    return 0;
}

void generateMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void multiplyMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int size) {
    int result[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix1[i][j] = result[i][j];
        }
    }
}