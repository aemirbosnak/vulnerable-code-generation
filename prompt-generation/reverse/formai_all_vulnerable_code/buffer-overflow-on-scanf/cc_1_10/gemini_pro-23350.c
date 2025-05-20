//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the matrices
#define MAX_SIZE 10

// Define the data type of the matrix elements
typedef int matrix_element_type;

// Define the structure of a matrix
typedef struct {
    int num_rows;
    int num_cols;
    matrix_element_type **data;
} matrix;

// Function to create a new matrix
matrix *create_matrix(int num_rows, int num_cols) {
    matrix *m = malloc(sizeof(matrix));
    if (m == NULL) {
        return NULL;
    }

    m->num_rows = num_rows;
    m->num_cols = num_cols;

    m->data = malloc(sizeof(matrix_element_type *) * num_rows);
    if (m->data == NULL) {
        free(m);
        return NULL;
    }

    for (int i = 0; i < num_rows; i++) {
        m->data[i] = malloc(sizeof(matrix_element_type) * num_cols);
        if (m->data[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(m->data[j]);
            }
            free(m->data);
            free(m);
            return NULL;
        }
    }

    return m;
}

// Function to free the memory allocated for a matrix
void free_matrix(matrix *m) {
    if (m == NULL) {
        return;
    }

    for (int i = 0; i < m->num_rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

// Function to print a matrix
void print_matrix(matrix *m) {
    if (m == NULL) {
        return;
    }

    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix *add_matrices(matrix *m1, matrix *m2) {
    if (m1 == NULL || m2 == NULL) {
        return NULL;
    }

    if (m1->num_rows != m2->num_rows || m1->num_cols != m2->num_cols) {
        return NULL;
    }

    matrix *result = create_matrix(m1->num_rows, m1->num_cols);
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < m1->num_rows; i++) {
        for (int j = 0; j < m1->num_cols; j++) {
            result->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
matrix *subtract_matrices(matrix *m1, matrix *m2) {
    if (m1 == NULL || m2 == NULL) {
        return NULL;
    }

    if (m1->num_rows != m2->num_rows || m1->num_cols != m2->num_cols) {
        return NULL;
    }

    matrix *result = create_matrix(m1->num_rows, m1->num_cols);
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < m1->num_rows; i++) {
        for (int j = 0; j < m1->num_cols; j++) {
            result->data[i][j] = m1->data[i][j] - m2->data[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices
matrix *multiply_matrices(matrix *m1, matrix *m2) {
    if (m1 == NULL || m2 == NULL) {
        return NULL;
    }

    if (m1->num_cols != m2->num_rows) {
        return NULL;
    }

    matrix *result = create_matrix(m1->num_rows, m2->num_cols);
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < m1->num_rows; i++) {
        for (int j = 0; j < m2->num_cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < m1->num_cols; k++) {
                result->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }

    return result;
}

// Function to read a matrix from the user
matrix *read_matrix() {
    int num_rows, num_cols;

    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);

    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);

    matrix *m = create_matrix(num_rows, num_cols);
    if (m == NULL) {
        return NULL;
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("Enter the element at row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &m->data[i][j]);
        }
    }

    return m;
}

// Function to test the matrix operations
void test_matrix_operations() {
    matrix *m1 = read_matrix();
    if (m1 == NULL) {
        printf("Error: Could not read matrix 1.\n");
        return;
    }

    matrix *m2 = read_matrix();
    if (m2 == NULL) {
        printf("Error: Could not read matrix 2.\n");
        free_matrix(m1);
        return;
    }

    printf("Matrix 1:\n");
    print_matrix(m1);

    printf("Matrix 2:\n");
    print_matrix(m2);

    matrix *m3 = add_matrices(m1, m2);
    if (m3 == NULL) {
        printf("Error: Could not add matrices.\n");
    } else {
        printf("Addition of matrices:\n");
        print_matrix(m3);
        free_matrix(m3);
    }

    matrix *m4 = subtract_matrices(m1, m2);
    if (m4 == NULL) {
        printf("Error: Could not subtract matrices.\n");
    } else {
        printf("Subtraction of matrices:\n");
        print_matrix(m4);
        free_matrix(m4);
    }

    matrix *m5 = multiply_matrices(m1, m2);
    if (m5 == NULL) {
        printf("Error: Could not multiply matrices.\n");
    } else {
        printf("Multiplication of matrices:\n");
        print_matrix(m5);
        free_matrix(m5);
    }

    free_matrix(m1);
    free_matrix(m2);
}

// Main function
int main() {
    test_matrix_operations();

    return 0;
}