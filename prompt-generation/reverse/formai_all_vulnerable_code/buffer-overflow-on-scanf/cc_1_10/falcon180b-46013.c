//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MIN_VALUE -1000
#define MAX_VALUE 1000

void fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size);
void multiply_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int size;
    printf("Enter the size of the matrices (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);

    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    fill_matrix(matrix1, size);
    fill_matrix(matrix2, size);

    printf("\nMatrix 1:\n");
    print_matrix(matrix1, size);

    printf("\nMatrix 2:\n");
    print_matrix(matrix2, size);

    multiply_matrices(matrix1, matrix2, result, size);

    printf("\nResult:\n");
    print_matrix(result, size);

    return 0;
}

void fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
}

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}