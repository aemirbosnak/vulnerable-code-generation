//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: interoperable
// Example program in a interoperable style for C Matrix operations

#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a matrix
struct matrix {
    int rows;
    int cols;
    double *data;
};

// Function to create a matrix
struct matrix create_matrix(int rows, int cols) {
    struct matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = malloc(rows * cols * sizeof(double));
    return m;
}

// Function to access a matrix element
double get_element(struct matrix m, int row, int col) {
    return m.data[row * m.cols + col];
}

// Function to set a matrix element
void set_element(struct matrix m, int row, int col, double value) {
    m.data[row * m.cols + col] = value;
}

// Function to add two matrices
struct matrix add_matrices(struct matrix m1, struct matrix m2) {
    struct matrix result = create_matrix(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            set_element(result, i, j, get_element(m1, i, j) + get_element(m2, i, j));
        }
    }
    return result;
}

// Function to multiply two matrices
struct matrix multiply_matrices(struct matrix m1, struct matrix m2) {
    struct matrix result = create_matrix(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            double sum = 0;
            for (int k = 0; k < m1.cols; k++) {
                sum += get_element(m1, i, k) * get_element(m2, k, j);
            }
            set_element(result, i, j, sum);
        }
    }
    return result;
}

int main() {
    // Create two matrices
    struct matrix m1 = create_matrix(2, 3);
    struct matrix m2 = create_matrix(3, 2);

    // Set matrix elements
    set_element(m1, 0, 0, 1.0);
    set_element(m1, 0, 1, 2.0);
    set_element(m1, 0, 2, 3.0);
    set_element(m1, 1, 0, 4.0);
    set_element(m1, 1, 1, 5.0);
    set_element(m1, 1, 2, 6.0);

    set_element(m2, 0, 0, 7.0);
    set_element(m2, 0, 1, 8.0);
    set_element(m2, 1, 0, 9.0);
    set_element(m2, 1, 1, 10.0);
    set_element(m2, 2, 0, 11.0);
    set_element(m2, 2, 1, 12.0);

    // Add the matrices
    struct matrix m3 = add_matrices(m1, m2);

    // Multiply the matrices
    struct matrix m4 = multiply_matrices(m1, m2);

    // Print the results
    printf("M1:\n");
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            printf("%.1f ", get_element(m1, i, j));
        }
        printf("\n");
    }

    printf("M2:\n");
    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            printf("%.1f ", get_element(m2, i, j));
        }
        printf("\n");
    }

    printf("M1 + M2:\n");
    for (int i = 0; i < m3.rows; i++) {
        for (int j = 0; j < m3.cols; j++) {
            printf("%.1f ", get_element(m3, i, j));
        }
        printf("\n");
    }

    printf("M1 * M2:\n");
    for (int i = 0; i < m4.rows; i++) {
        for (int j = 0; j < m4.cols; j++) {
            printf("%.1f ", get_element(m4, i, j));
        }
        printf("\n");
    }

    return 0;
}