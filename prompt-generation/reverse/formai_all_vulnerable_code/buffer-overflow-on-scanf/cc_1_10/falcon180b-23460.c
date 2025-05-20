//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void generate_matrix(int matrix[MAX][MAX], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    int size;

    printf("Enter the size of the matrices (maximum %d): ", MAX);
    scanf("%d", &size);

    generate_matrix(matrix1, size);
    generate_matrix(matrix2, size);

    printf("Matrix 1:\n");
    print_matrix(matrix1, size);

    printf("Matrix 2:\n");
    print_matrix(matrix2, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Sum of matrices:\n");
    print_matrix(result, size);

    return 0;
}