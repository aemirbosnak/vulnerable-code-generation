//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

// function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to multiply two matrices
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int columns1, int rows2, int columns2) {
    int i, j, k;
    for(i=0; i<rows1; i++) {
        for(j=0; j<columns2; j++) {
            result[i][j] = 0;
            for(k=0; k<columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// function to generate a random matrix
void generateRandomMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    srand(time(NULL));
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    int rows1, columns1, rows2, columns2;
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &columns1);
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &columns2);

    // check if matrices can be multiplied
    if(columns1!= rows2) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }

    // generate random matrices
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    generateRandomMatrix(matrix1, rows1, columns1);
    generateRandomMatrix(matrix2, rows2, columns2);

    // print matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, columns1);
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, columns2);

    // multiply matrices
    multiplyMatrices(matrix1, matrix2, result, rows1, columns1, rows2, columns2);

    // print result
    printf("Result:\n");
    printMatrix(result, rows1, columns2);

    return 0;
}