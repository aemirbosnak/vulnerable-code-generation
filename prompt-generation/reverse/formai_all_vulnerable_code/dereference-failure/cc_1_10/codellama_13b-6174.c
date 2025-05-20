//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: energetic
/*
 * Matrix operations example program
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Matrix initialization function
void init_matrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
    }
}

// Matrix addition function
void add_matrix(Matrix *a, Matrix *b, Matrix *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

// Matrix multiplication function
void multiply_matrix(Matrix *a, Matrix *b, Matrix *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
}

// Matrix transpose function
void transpose_matrix(Matrix *a, Matrix *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            b->data[j][i] = a->data[i][j];
        }
    }
}

// Matrix printing function
void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Matrix a, b, c;
    init_matrix(&a, 2, 2);
    init_matrix(&b, 2, 2);
    init_matrix(&c, 2, 2);

    // Initialize matrix data
    a.data[0][0] = 1;
    a.data[0][1] = 2;
    a.data[1][0] = 3;
    a.data[1][1] = 4;

    b.data[0][0] = 5;
    b.data[0][1] = 6;
    b.data[1][0] = 7;
    b.data[1][1] = 8;

    // Add matrices
    add_matrix(&a, &b, &c);
    printf("Addition: \n");
    print_matrix(&c);

    // Multiply matrices
    multiply_matrix(&a, &b, &c);
    printf("Multiplication: \n");
    print_matrix(&c);

    // Transpose matrix
    transpose_matrix(&a, &b);
    printf("Transpose: \n");
    print_matrix(&b);

    return 0;
}