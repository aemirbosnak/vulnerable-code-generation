//FormAI DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void matrix_add(int **matrix1, int **matrix2, int **result, int rows, int cols);
void matrix_subtract(int **matrix1, int **matrix2, int **result, int rows, int cols);
void matrix_multiply(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int rows2, int cols2);
void matrix_transpose(int **matrix, int **result, int rows, int cols);
void matrix_display(int **matrix, int rows, int cols);
void matrix_free(int **matrix, int rows);

int main() {
    int rows1, cols1, rows2, cols2, i, j;
    int **matrix1, **matrix2, **result;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    /* Allocate memory for the first matrix */
    matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for(i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    /* Check if matrix multiplication is possible */
    if(cols1 != rows2) {
        printf("Matrix multiplication is not possible\n");
        return 0;
    }

    /* Allocate memory for the second matrix */
    matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for(i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    printf("Enter the elements of the second matrix:\n");
    for(i = 0; i < rows2; i++) {
        for(j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    /* Allocate memory for the result matrix */
    result = (int **)malloc(rows1 * sizeof(int *));
    for(i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    printf("Performing matrix operations...\n");
    printf("Matrix 1:\n");
    matrix_display(matrix1, rows1, cols1);
    printf("Matrix 2:\n");
    matrix_display(matrix2, rows2, cols2);

    /* Matrix addition */
    matrix_add(matrix1, matrix2, result, rows1, cols1);
    printf("Matrix addition:\n");
    matrix_display(result, rows1, cols1);

    /* Matrix subtraction */
    matrix_subtract(matrix1, matrix2, result, rows1, cols1);
    printf("Matrix subtraction:\n");
    matrix_display(result, rows1, cols1);

    /* Matrix multiplication */
    matrix_multiply(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
    printf("Matrix multiplication:\n");
    matrix_display(result, rows1, cols2);

    /* Matrix transpose */
    matrix_transpose(matrix1, result, rows1, cols1);
    printf("Transpose of matrix 1:\n");
    matrix_display(result, cols1, rows1);

    /* Free memory */
    matrix_free(matrix1, rows1);
    matrix_free(matrix2, rows2);
    matrix_free(result, rows1);

    return 0;
}

/* Function to perform matrix addition */
void matrix_add(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/* Function to perform matrix subtraction */
void matrix_subtract(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

/* Function to perform matrix multiplication */
void matrix_multiply(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;

    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

/* Function to perform matrix transpose */
void matrix_transpose(int **matrix, int **result, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

/* Function to display matrix */
void matrix_display(int **matrix, int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to free memory */
void matrix_free(int **matrix, int rows) {
    int i;
    for(i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}