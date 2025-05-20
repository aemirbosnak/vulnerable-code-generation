//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: ephemeral
/*
 * Matrix operations example program in ephemeral style.
 *
 * This program demonstrates the basic matrix operations in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 100

// Matrix structure
typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

// Function prototypes
void init_matrix(Matrix* m, int rows, int cols);
void print_matrix(Matrix m);
Matrix* create_matrix(int rows, int cols);
void destroy_matrix(Matrix* m);
Matrix* transpose(Matrix m);
Matrix* add_matrix(Matrix a, Matrix b);
Matrix* multiply_matrix(Matrix a, Matrix b);

// Main function
int main() {
    // Initialize matrices
    Matrix* A = create_matrix(2, 3);
    Matrix* B = create_matrix(2, 3);
    Matrix* C = create_matrix(2, 3);

    // Initialize matrix data
    int i, j;
    for (i = 0; i < A->rows; i++) {
        for (j = 0; j < A->cols; j++) {
            A->data[i][j] = (double)(i + j + 1);
        }
    }
    for (i = 0; i < B->rows; i++) {
        for (j = 0; j < B->cols; j++) {
            B->data[i][j] = (double)(i + j + 1);
        }
    }

    // Perform matrix operations
    C = transpose(*A);
    print_matrix(*C);
    C = add_matrix(*A, *B);
    print_matrix(*C);
    C = multiply_matrix(*A, *B);
    print_matrix(*C);

    // Destroy matrices
    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(C);

    return 0;
}

// Matrix initialization function
void init_matrix(Matrix* m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (double**)malloc(rows * sizeof(double*));
    int i;
    for (i = 0; i < rows; i++) {
        m->data[i] = (double*)malloc(cols * sizeof(double));
    }
}

// Matrix print function
void print_matrix(Matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%lf ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Matrix creation function
Matrix* create_matrix(int rows, int cols) {
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    init_matrix(m, rows, cols);
    return m;
}

// Matrix destruction function
void destroy_matrix(Matrix* m) {
    int i;
    for (i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

// Matrix transpose function
Matrix* transpose(Matrix m) {
    Matrix* m_trans = create_matrix(m.cols, m.rows);
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            m_trans->data[j][i] = m.data[i][j];
        }
    }
    return m_trans;
}

// Matrix addition function
Matrix* add_matrix(Matrix a, Matrix b) {
    Matrix* c = create_matrix(a.rows, a.cols);
    int i, j;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            c->data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

// Matrix multiplication function
Matrix* multiply_matrix(Matrix a, Matrix b) {
    Matrix* c = create_matrix(a.rows, b.cols);
    int i, j, k;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < b.cols; j++) {
            c->data[i][j] = 0;
            for (k = 0; k < a.cols; k++) {
                c->data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}