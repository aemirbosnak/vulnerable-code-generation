//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_SIZE 1
#define MAX_VALUE 1000
#define MIN_VALUE 1

int generate_random_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
    return 0;
}

int multiply_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return 0;
}

int print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int size, matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("Enter the size of the matrices (between %d and %d): ", MIN_SIZE, MAX_SIZE);
    scanf("%d", &size);

    while (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid size. Please enter a size between %d and %d: ", MIN_SIZE, MAX_SIZE);
        scanf("%d", &size);
    }

    generate_random_matrix(matrix1, size);
    generate_random_matrix(matrix2, size);

    printf("Matrix 1:\n");
    print_matrix(matrix1, size);

    printf("Matrix 2:\n");
    print_matrix(matrix2, size);

    multiply_matrices(matrix1, matrix2, result, size);

    printf("Result:\n");
    print_matrix(result, size);

    return 0;
}