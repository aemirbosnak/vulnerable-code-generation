//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the matrices
#define MAX_SIZE 100

// Define the data type of the matrices
typedef int matrix[MAX_SIZE][MAX_SIZE];

// Define the function to add two matrices
void add_matrices(matrix a, matrix b, matrix c, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Define the function to subtract two matrices
void subtract_matrices(matrix a, matrix b, matrix c, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Define the function to multiply two matrices
void multiply_matrices(matrix a, matrix b, matrix c, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c[i][j] = 0;
            for (int k = 0; k < size; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Define the function to print a matrix
void print_matrix(matrix a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Define the main function
int main() {
    // Define the size of the matrices
    int size;
    printf("Enter the size of the matrices: ");
    scanf("%d", &size);

    // Define the three matrices
    matrix a, b, c;

    // Get the values of the first matrix
    printf("Enter the values of the first matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Get the values of the second matrix
    printf("Enter the values of the second matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Add the two matrices
    add_matrices(a, b, c, size);

    // Print the result of the addition
    printf("The sum of the two matrices is:\n");
    print_matrix(c, size);

    // Subtract the two matrices
    subtract_matrices(a, b, c, size);

    // Print the result of the subtraction
    printf("The difference of the two matrices is:\n");
    print_matrix(c, size);

    // Multiply the two matrices
    multiply_matrices(a, b, c, size);

    // Print the result of the multiplication
    printf("The product of the two matrices is:\n");
    print_matrix(c, size);

    return 0;
}