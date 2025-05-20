//Falcon-180B DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int **createMatrix(int size) {
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(size * sizeof(int));
    }
    return matrix;
}

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int sumMatrix(int **matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int sumRows(int **matrix, int size, int row) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[row][i];
    }
    return sum;
}

int sumColumns(int **matrix, int size, int column) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][column];
    }
    return sum;
}

int main() {
    int **matrix = createMatrix(SIZE);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = i * SIZE + j + 1;
        }
    }

    printMatrix(matrix, SIZE);

    int sum = sumMatrix(matrix, SIZE);
    printf("Sum of matrix: %d\n", sum);

    int sumRow = sumRows(matrix, SIZE, 1);
    printf("Sum of row 1: %d\n", sumRow);

    int sumColumn = sumColumns(matrix, SIZE, 2);
    printf("Sum of column 2: %d\n", sumColumn);

    for (int i = 0; i < SIZE; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}