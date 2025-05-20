//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define SIZE 2

void add_matrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply_matrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int determinant(int matrix[SIZE][SIZE]) {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixA[SIZE][SIZE], matrixB[SIZE][SIZE];
    int sum[SIZE][SIZE], product[SIZE][SIZE];

    printf("Enter elements of first 2x2 matrix:\n");
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &matrixA[i][j]);

    printf("Enter elements of second 2x2 matrix:\n");
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &matrixB[i][j]);

    printf("\nMatrix A:\n");
    print_matrix(matrixA);

    printf("\nMatrix B:\n");
    print_matrix(matrixB);
    
    add_matrices(matrixA, matrixB, sum);
    printf("\nSum of A and B:\n");
    print_matrix(sum);
    
    multiply_matrices(matrixA, matrixB, product);
    printf("\nProduct of A and B:\n");
    print_matrix(product);
    
    int detA = determinant(matrixA);
    int detB = determinant(matrixB);
    
    printf("\nDeterminant of Matrix A: %d\n", detA);
    printf("Determinant of Matrix B: %d\n", detB);
    
    return 0;
}