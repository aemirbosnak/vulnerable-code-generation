//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void create_matrix(int **matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2, i, j, k;
    int **matrix1, **matrix2, **result;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    create_matrix(matrix1, rows1, cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1!= rows2) {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }

    matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols1 * sizeof(int));
    }

    printf("Enter the elements of the second matrix:\n");
    create_matrix(matrix2, rows2, cols1);

    result = (int **)malloc(rows1 * sizeof(int *));
    for (i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Result of matrix multiplication:\n");
    print_matrix(result, rows1, cols2);

    for (i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}