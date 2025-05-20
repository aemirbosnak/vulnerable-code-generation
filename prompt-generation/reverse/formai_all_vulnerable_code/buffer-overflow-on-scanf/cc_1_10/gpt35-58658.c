//FormAI DATASET v1.0 Category: Matrix operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void printMatrix(int arr[MAX_SIZE][MAX_SIZE], int row, int col);
void addMatrix(int arr1[MAX_SIZE][MAX_SIZE], int arr2[MAX_SIZE][MAX_SIZE], int row, int col);
void subtractMatrix(int arr1[MAX_SIZE][MAX_SIZE], int arr2[MAX_SIZE][MAX_SIZE], int row, int col);
void multiplyMatrix(int arr1[MAX_SIZE][MAX_SIZE], int arr2[MAX_SIZE][MAX_SIZE], int row, int col);

int main() {
    int row, col;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &row, &col);
    printf("Enter the first matrix: \n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the second matrix: \n");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("\nFirst Matrix: \n");
    printMatrix(matrix1, row, col);

    printf("Second Matrix: \n");
    printMatrix(matrix2, row, col);

    printf("Addition of matrices: \n");
    addMatrix(matrix1, matrix2, row, col);

    printf("Subtraction of matrices: \n");
    subtractMatrix(matrix1, matrix2, row, col);

    printf("Multiplication of matrices: \n");
    multiplyMatrix(matrix1, matrix2, row, col);

    return 0;
}

void printMatrix(int arr[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int arr1[MAX_SIZE][MAX_SIZE], int arr2[MAX_SIZE][MAX_SIZE], int row, int col) {
    int sum[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void subtractMatrix(int arr1[MAX_SIZE][MAX_SIZE], int arr2[MAX_SIZE][MAX_SIZE], int row, int col) {
    int difference[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            difference[i][j] = arr1[i][j] - arr2[i][j];
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int arr1[MAX_SIZE][MAX_SIZE], int arr2[MAX_SIZE][MAX_SIZE], int row, int col) {
    int product[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            product[i][j] = 0;
            for (int k = 0; k < col; ++k) {
                product[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}