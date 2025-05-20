//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add_matrix(int **A, int **B, int **C, int n_rows, int n_cols) {
    for(int i = 0; i < n_rows; i++) {
        for(int j = 0; j < n_cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void sub_matrix(int **A, int **B, int **C, int n_rows, int n_cols) {
    for(int i = 0; i < n_rows; i++) {
        for(int j = 0; j < n_cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to print a matrix
void print_matrix(int **A, int n_rows, int n_cols) {
    for(int i = 0; i < n_rows; i++) {
        for(int j = 0; j < n_cols; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Matrix Operations Program!\n");
    printf("In this program, we will perform addition and subtraction of matrices.\n");
    printf("Let's start by creating two matrices.\n");

    // Get the size of the matrices
    int n_rows, n_cols;
    printf("Enter number of rows: ");
    scanf("%d", &n_rows);
    printf("Enter number of columns: ");
    scanf("%d", &n_cols);

    // Allocate memory for the matrices
    int **A = (int **)malloc(n_rows * sizeof(int *));
    int **B = (int **)malloc(n_rows * sizeof(int *));
    int **C = (int **)malloc(n_rows * sizeof(int *));
    for(int i = 0; i < n_rows; i++) {
        A[i] = (int *)malloc(n_cols * sizeof(int));
        B[i] = (int *)malloc(n_cols * sizeof(int));
        C[i] = (int *)malloc(n_cols * sizeof(int));
    }

    // Get the elements of the matrices
    printf("Enter the elements of matrix A:\n");
    for(int i = 0; i < n_rows; i++) {
        for(int j = 0; j < n_cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for(int i = 0; i < n_rows; i++) {
        for(int j = 0; j < n_cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("The matrices you entered are:\n");
    printf("Matrix A:\n");
    print_matrix(A, n_rows, n_cols);
    printf("\n");
    printf("Matrix B:\n");
    print_matrix(B, n_rows, n_cols);
    printf("\n");

    // Perform addition of matrices and display the result
    printf("Performing addition of matrices...\n");
    add_matrix(A, B, C, n_rows, n_cols);
    printf("The result of addition is:\n");
    print_matrix(C, n_rows, n_cols);
    printf("\n");

    // Perform subtraction of matrices and display the result
    printf("Performing subtraction of matrices...\n");
    sub_matrix(A, B, C, n_rows, n_cols);
    printf("The result of subtraction is:\n");
    print_matrix(C, n_rows, n_cols);

    // Free the memory allocated for the matrices
    for(int i = 0; i < n_rows; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    printf("\nThank you for using the Matrix Operations Program! Goodbye!\n");
    return 0;
}