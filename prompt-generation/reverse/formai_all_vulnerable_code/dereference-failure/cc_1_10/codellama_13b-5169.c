//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
// A unique C Matrix operations example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the matrix data structure
struct matrix {
    int rows;
    int cols;
    int** data;
};

// Initialize a matrix with the given dimensions
struct matrix* init_matrix(int rows, int cols) {
    struct matrix* m = malloc(sizeof(struct matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
    }
    return m;
}

// Free the memory allocated for the matrix
void free_matrix(struct matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

// Print the matrix to the console
void print_matrix(struct matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices
struct matrix* add_matrices(struct matrix* m1, struct matrix* m2) {
    struct matrix* m3 = init_matrix(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            m3->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return m3;
}

// Subtract two matrices
struct matrix* subtract_matrices(struct matrix* m1, struct matrix* m2) {
    struct matrix* m3 = init_matrix(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            m3->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }
    return m3;
}

// Multiply two matrices
struct matrix* multiply_matrices(struct matrix* m1, struct matrix* m2) {
    struct matrix* m3 = init_matrix(m1->rows, m2->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            for (int k = 0; k < m1->cols; k++) {
                m3->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return m3;
}

// Transpose a matrix
struct matrix* transpose_matrix(struct matrix* m) {
    struct matrix* m_trans = init_matrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m_trans->data[j][i] = m->data[i][j];
        }
    }
    return m_trans;
}

// Main function
int main() {
    // Initialize two matrices
    struct matrix* m1 = init_matrix(3, 3);
    struct matrix* m2 = init_matrix(3, 3);

    // Fill the matrices with some data
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1->data[i][j] = i * j;
            m2->data[i][j] = j * (i + 1);
        }
    }

    // Print the matrices
    print_matrix(m1);
    print_matrix(m2);

    // Perform some matrix operations
    struct matrix* m3 = add_matrices(m1, m2);
    struct matrix* m4 = subtract_matrices(m1, m2);
    struct matrix* m5 = multiply_matrices(m1, m2);
    struct matrix* m6 = transpose_matrix(m1);

    // Print the results
    print_matrix(m3);
    print_matrix(m4);
    print_matrix(m5);
    print_matrix(m6);

    // Free the memory
    free_matrix(m1);
    free_matrix(m2);
    free_matrix(m3);
    free_matrix(m4);
    free_matrix(m5);
    free_matrix(m6);

    return 0;
}