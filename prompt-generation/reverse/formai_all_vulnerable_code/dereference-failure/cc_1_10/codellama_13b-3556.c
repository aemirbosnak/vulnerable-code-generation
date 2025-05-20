//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
// Romeo and Juliet Matrix Operations Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_SIZE 25

// Matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Matrix operations
void initMatrix(Matrix *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = 0;
        }
    }
}

void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(Matrix mat1, Matrix mat2, Matrix *result) {
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result->data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
}

void subMatrix(Matrix mat1, Matrix mat2, Matrix *result) {
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result->data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }
}

void mulMatrix(Matrix mat1, Matrix mat2, Matrix *result) {
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result->data[i][j] = mat1.data[i][j] * mat2.data[i][j];
        }
    }
}

void divMatrix(Matrix mat1, Matrix mat2, Matrix *result) {
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result->data[i][j] = mat1.data[i][j] / mat2.data[i][j];
        }
    }
}

int main() {
    // Initialize matrices
    Matrix mat1, mat2, result;
    initMatrix(&mat1, 5, 5);
    initMatrix(&mat2, 5, 5);
    initMatrix(&result, 5, 5);

    // Set matrix values
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            mat1.data[i][j] = i * j;
            mat2.data[i][j] = j * j;
        }
    }

    // Perform matrix operations
    addMatrix(mat1, mat2, &result);
    printMatrix(result);
    subMatrix(mat1, mat2, &result);
    printMatrix(result);
    mulMatrix(mat1, mat2, &result);
    printMatrix(result);
    divMatrix(mat1, mat2, &result);
    printMatrix(result);

    // Free memory
    free(mat1.data);
    free(mat2.data);
    free(result.data);

    return 0;
}