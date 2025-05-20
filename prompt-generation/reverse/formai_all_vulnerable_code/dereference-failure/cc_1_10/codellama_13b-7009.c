//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Matrix struct
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

// Matrix operations
void matrix_init(Matrix* m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int*)malloc(cols * sizeof(int));
    }
}

void matrix_free(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

void matrix_print(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(Matrix* m1, Matrix* m2) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            m1->data[i][j] += m2->data[i][j];
        }
    }
}

void matrix_subtract(Matrix* m1, Matrix* m2) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            m1->data[i][j] -= m2->data[i][j];
        }
    }
}

void matrix_multiply(Matrix* m1, Matrix* m2) {
    Matrix result;
    matrix_init(&result, m1->rows, m2->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            for (int k = 0; k < m1->cols; k++) {
                result.data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    matrix_free(m1);
    matrix_free(m2);
    *m1 = result;
}

int main() {
    Matrix m1, m2;
    matrix_init(&m1, 2, 3);
    matrix_init(&m2, 2, 3);

    m1.data[0][0] = 1;
    m1.data[0][1] = 2;
    m1.data[0][2] = 3;
    m1.data[1][0] = 4;
    m1.data[1][1] = 5;
    m1.data[1][2] = 6;

    m2.data[0][0] = 7;
    m2.data[0][1] = 8;
    m2.data[0][2] = 9;
    m2.data[1][0] = 10;
    m2.data[1][1] = 11;
    m2.data[1][2] = 12;

    matrix_add(&m1, &m2);
    matrix_print(&m1);

    matrix_subtract(&m1, &m2);
    matrix_print(&m1);

    matrix_multiply(&m1, &m2);
    matrix_print(&m1);

    matrix_free(&m1);
    matrix_free(&m2);

    return 0;
}