//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MATRIX_SIZE 10
#define DATA_TYPE float

typedef struct {
    DATA_TYPE elements[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
    int rows;
    int cols;
} Matrix;

Matrix create_matrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix.elements[i][j] = 0.0f;
        }
    }
    return matrix;
}

Matrix read_matrix_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    Matrix matrix;
    int rows = 0, cols = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (cols == 0) {
            sscanf(line, "%d", &cols);
        } else {
            if (rows == 0) {
                sscanf(line, "%d", &rows);
            } else {
                for (int i = 0; i < rows; i++) {
                    sscanf(line + strlen(line) - cols * (sizeof(int) + sizeof(DATA_TYPE)), "%f,%f%*[^\n]",
                           &matrix.elements[i][cols - 1], &matrix.elements[i][cols - 2]);
                }
            }
        }
    }

    matrix = create_matrix(rows, cols);
    fclose(file);
    return matrix;
}

void print_matrix(const Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%g ", matrix->elements[i][j]);
        }
        printf("\n");
    }
}

Matrix add_matrices(const Matrix* a, const Matrix* b) {
    Matrix result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.elements[i][j] += a->elements[i][j] + b->elements[i][j];
        }
    }
    return result;
}

Matrix subtract_matrices(const Matrix* a, const Matrix* b) {
    Matrix result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.elements[i][j] += a->elements[i][j] - b->elements[i][j];
        }
    }
    return result;
}

Matrix multiply_matrices(const Matrix* a, const Matrix* b) {
    Matrix result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            for (int k = 0; k < a->cols; k++) {
                result.elements[i][j] += a->elements[i][k] * b->elements[k][j];
            }
        }
    }
    return result;
}

void free_matrix(Matrix* matrix) {
    free(matrix);
}

int main() {
    Matrix A = read_matrix_from_file("matrixA.txt");
    Matrix B = read_matrix_from_file("matrixB.txt");

    if (A.rows != B.rows || A.cols != B.cols) {
        fprintf(stderr, "Matrices have different sizes\n");
        free_matrix(&A);
        free_matrix(&B);
        return EXIT_FAILURE;
    }

    Matrix C = multiply_matrices(&A, &B);

    print_matrix(&A);
    printf("\n");
    print_matrix(&B);
    printf("\n");
    print_matrix(&C);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);

    return EXIT_SUCCESS;
}