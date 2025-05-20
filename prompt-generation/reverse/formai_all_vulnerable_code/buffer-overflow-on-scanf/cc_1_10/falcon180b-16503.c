//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define MIN 1

void create_matrix(int matrix[MAX][MAX], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = rand() % (MAX - MIN + 1) + MIN;
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int matrix[MAX][MAX], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = matrix[j][i];
        }
    }
}

void multiply_matrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int size) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = 0;
            for (k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX], size;
    printf("Enter the size of the matrices: ");
    scanf("%d", &size);
    if (size < MIN || size > MAX) {
        printf("Invalid size. Please enter a number between %d and %d.\n", MIN, MAX);
        return 1;
    }
    create_matrix(matrix1, size);
    print_matrix(matrix1, size);
    create_matrix(matrix2, size);
    print_matrix(matrix2, size);
    multiply_matrices(matrix1, matrix2, result, size);
    printf("The product of the matrices is:\n");
    print_matrix(result, size);
    return 0;
}