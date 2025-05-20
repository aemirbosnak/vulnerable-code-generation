//FormAI DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>

#define ROW 3
#define COL 3

int matrix_a[ROW][COL];
int matrix_b[ROW][COL];

void matrix_input(int matrix[][COL], const char* name) {
    printf("Enter the elements for matrix %s:\n", name);
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_output(int matrix[][COL], const char* name) {
    printf("\nThe matrix %s:\n", name);
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(int result[][COL] , int matrix1[][COL], int matrix2[][COL]) {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_multiply(int result[][COL], int matrix1[][COL], int matrix2[][COL]) {
    int sum;
    for (int k = 0; k < ROW; ++k) {
        for (int j = 0; j < COL; ++j) {
            sum = 0;
            for (int i = 0; i < ROW; ++i) {
                sum += matrix1[k][i] * matrix2[i][j];
            }
            result[k][j] = sum;
        }
    }
}

int main() {
    matrix_input(matrix_a, "A");
    matrix_input(matrix_b, "B");

    int result_add[ROW][COL];
    matrix_add(result_add, matrix_a, matrix_b);

    matrix_output(result_add, "A + B");

    int result_multiply[ROW][COL];
    matrix_multiply(result_multiply, matrix_a, matrix_b);

    matrix_output(result_multiply, "A * B");

    return 0;
}