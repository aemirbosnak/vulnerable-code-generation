//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int rows;
    int cols;
    int **arr;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->arr = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->arr[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->arr[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix(Matrix *matrix, int start, int end) {
    int count = 1;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            if (i % 2 == 0) {
                matrix->arr[i][j] = count++;
            } else {
                matrix->arr[i][matrix->cols - j - 1] = count++;
            }
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    Matrix *matrix = create_matrix(rows, cols);
    fill_matrix(matrix, 1, rows * cols);
    print_matrix(matrix);
    free_matrix(matrix);
    return 0;
}