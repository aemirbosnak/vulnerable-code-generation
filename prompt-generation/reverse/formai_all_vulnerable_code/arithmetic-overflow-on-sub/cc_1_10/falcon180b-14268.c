//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate a random matrix of given size
void generate_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print a given matrix
void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two given matrices
void multiply_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to benchmark matrix multiplication
void benchmark_matrix_multiplication(int size) {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    generate_matrix(matrix1, size);
    generate_matrix(matrix2, size);

    clock_t start_time = clock();
    multiply_matrices(matrix1, matrix2, result, size);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication of size %d: %.6f seconds\n", size, elapsed_time);
}

int main() {
    int size;
    printf("Enter the size of the matrices: ");
    scanf("%d", &size);

    benchmark_matrix_multiplication(size);

    return 0;
}