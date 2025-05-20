//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

void create_matrix(Matrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j] = 0;
        }
    }
}

void destroy_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void generate_fibonacci(Matrix *matrix) {
    int row = 0;
    int col = 0;
    matrix->data[row][col] = 0;
    matrix->data[row][col + 1] = 1;

    for (int i = 2; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols - 1; j++) {
            matrix->data[i][j] = matrix->data[i - 1][j] + matrix->data[i - 2][j];
        }
        matrix->data[i][matrix->cols - 1] = matrix->data[i - 1][matrix->cols - 1];
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Input values are too large.\n");
        return 1;
    }

    Matrix matrix;
    create_matrix(&matrix, rows, cols);

    generate_fibonacci(&matrix);

    printf("Fibonacci sequence:\n");
    print_matrix(&matrix);

    destroy_matrix(&matrix);

    return 0;
}