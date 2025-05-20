//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
// Ken Thompson style matrix operations program

#include <stdio.h>
#include <stdlib.h>

// Matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Matrix operations
void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(Matrix *m1, Matrix *m2, Matrix *result) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
}

void multiply_matrix(Matrix *m1, Matrix *m2, Matrix *result) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < m1->cols; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
}

int main() {
    // Initialize matrices
    Matrix m1 = {3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix m2 = {3, 3, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    Matrix result = {3, 3, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};

    // Print matrices
    print_matrix(&m1);
    print_matrix(&m2);

    // Add matrices
    add_matrix(&m1, &m2, &result);
    print_matrix(&result);

    // Multiply matrices
    multiply_matrix(&m1, &m2, &result);
    print_matrix(&result);

    return 0;
}