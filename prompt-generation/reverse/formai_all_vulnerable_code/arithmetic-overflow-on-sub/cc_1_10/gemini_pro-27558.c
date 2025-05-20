//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the matrices
#define MAX_SIZE 100

// Define the types of operations that can be performed
typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY
} Operation;

// Define the structure of a matrix
typedef struct {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

// Create a new matrix with the given dimensions
Matrix* create_matrix(int rows, int cols) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j] = 0;
        }
    }
    return matrix;
}

// Free the memory allocated for the matrix
void free_matrix(Matrix* matrix) {
    free(matrix);
}

// Print the matrix to the console
void print_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Perform the given operation on the two matrices
Matrix* perform_operation(Matrix* matrix1, Matrix* matrix2, Operation operation) {
    Matrix* result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            switch (operation) {
                case ADD:
                    result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
                    break;
                case SUBTRACT:
                    result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
                    break;
                case MULTIPLY:
                    result->data[i][j] = 0;
                    for (int k = 0; k < matrix1->cols; k++) {
                        result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
                    }
                    break;
            }
        }
    }
    return result;
}

// Get the input matrix from the user
Matrix* get_input_matrix(char* message) {
    int rows, cols;
    printf("%s", message);
    scanf("%d %d", &rows, &cols);
    Matrix* matrix = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix->data[i][j]);
        }
    }
    return matrix;
}

// Get the operation from the user
Operation get_operation(void) {
    int operation;
    printf("Enter the operation (1 for add, 2 for subtract, 3 for multiply): ");
    scanf("%d", &operation);
    return operation - 1;
}

// Main function
int main(void) {
    // Get the input matrices
    Matrix* matrix1 = get_input_matrix("Enter the first matrix:\n");
    Matrix* matrix2 = get_input_matrix("Enter the second matrix:\n");

    // Get the operation to be performed
    Operation operation = get_operation();

    // Perform the operation on the matrices
    Matrix* result = perform_operation(matrix1, matrix2, operation);

    // Print the result matrix
    printf("The result of the operation is:\n");
    print_matrix(result);

    // Free the memory allocated for the matrices
    free_matrix(matrix1);
    free_matrix(matrix2);
    free_matrix(result);

    return 0;
}