//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

void generateRandomMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size);
void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(double matrix1[MAX_SIZE][MAX_SIZE], double matrix2[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int size);
void transposeMatrix(double matrix[MAX_SIZE][MAX_SIZE], double transpose[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int size;
    double matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], transpose[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("Enter the size of the matrices (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    generateRandomMatrix(matrix1, size);
    printMatrix(matrix1, size);

    generateRandomMatrix(matrix2, size);
    printMatrix(matrix2, size);

    multiplyMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size);

    transposeMatrix(matrix1, transpose, size);
    printMatrix(transpose, size);

    return 0;
}

void generateRandomMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(double matrix1[MAX_SIZE][MAX_SIZE], double matrix2[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(double matrix[MAX_SIZE][MAX_SIZE], double transpose[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}