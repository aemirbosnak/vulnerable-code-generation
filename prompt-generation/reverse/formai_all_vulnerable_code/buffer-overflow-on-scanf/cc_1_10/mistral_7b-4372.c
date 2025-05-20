//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

typedef struct {
    double data[ROWS][COLS];
} Matrix;

void read_matrix(Matrix *matrix) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%lf", &(matrix->data[i][j]));
        }
    }
}

void print_matrix(const Matrix *matrix) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%.2f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix add_matrices(const Matrix *matrix1, const Matrix *matrix2) {
    Matrix result;
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result.data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

int main() {
    Matrix matrix1, matrix2, sum;
    printf("Enter elements for first matrix:\n");
    read_matrix(&matrix1);
    printf("Enter elements for second matrix:\n");
    read_matrix(&matrix2);
    sum = add_matrices(&matrix1, &matrix2);
    printf("First matrix:\n");
    print_matrix(&matrix1);
    printf("Second matrix:\n");
    print_matrix(&matrix2);
    printf("Sum of matrices:\n");
    print_matrix(&sum);
    return 0;
}