//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void init_matrix(int matrix[MAX][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
            for (k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transpose_matrix(int matrix[MAX][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX], n;
    srand(time(NULL));
    printf("Enter the number of rows and columns for the matrices (max 100): ");
    scanf("%d", &n);
    init_matrix(matrix1, n);
    init_matrix(matrix2, n);
    print_matrix(matrix1, n);
    print_matrix(matrix2, n);
    multiply_matrices(matrix1, matrix2, result, n);
    printf("\nResult of matrix multiplication:\n");
    print_matrix(result, n);
    transpose_matrix(result, n);
    printf("\nTranspose of result matrix:\n");
    print_matrix(result, n);
    return 0;
}