//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int **create_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void fill_matrix(int **matrix, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **matrix1 = create_matrix(rows, cols);
    int **matrix2 = create_matrix(rows, cols);
    int **result = create_matrix(rows, cols);

    fill_matrix(matrix1, rows, cols);
    fill_matrix(matrix2, rows, cols);

    printf("Matrix 1:\n");
    print_matrix(matrix1, rows, cols);

    printf("Matrix 2:\n");
    print_matrix(matrix2, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Sum of matrices:\n");
    print_matrix(result, rows, cols);

    free_matrix(matrix1, rows);
    free_matrix(matrix2, rows);
    free_matrix(result, rows);

    return 0;
}