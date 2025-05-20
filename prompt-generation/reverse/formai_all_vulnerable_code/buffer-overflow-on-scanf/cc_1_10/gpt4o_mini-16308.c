//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void print_matrix(int matrix[MAX][MAX], int rows, int cols);
void add_matrices(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows, int cols);
void subtract_matrices(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows, int cols);
void multiply_matrices(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows_a, int cols_a, int rows_b, int cols_b);
void input_matrix(int matrix[MAX][MAX], int rows, int cols);

int main() {
    int choice;
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int rows_a, cols_a, rows_b, cols_b;

    printf("***********************\n");
    printf("*  MATRIX OPERATIONS  *\n");
    printf("***********************\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of rows and columns for matrix A: ");
                scanf("%d %d", &rows_a, &cols_a);
                printf("Enter elements of matrix A:\n");
                input_matrix(a, rows_a, cols_a);

                printf("Enter number of rows and columns for matrix B (should be the same as A): ");
                scanf("%d %d", &rows_b, &cols_b);

                if (rows_a == rows_b && cols_a == cols_b) {
                    printf("Enter elements of matrix B:\n");
                    input_matrix(b, rows_b, cols_b);
                    add_matrices(a, b, c, rows_a, cols_a);
                    printf("Resulting Matrix (A + B):\n");
                    print_matrix(c, rows_a, cols_a);
                } else {
                    printf("Matrix dimensions do not match for addition!\n");
                }
                break;

            case 2:
                printf("Enter number of rows and columns for matrix A: ");
                scanf("%d %d", &rows_a, &cols_a);
                printf("Enter elements of matrix A:\n");
                input_matrix(a, rows_a, cols_a);

                printf("Enter number of rows and columns for matrix B (should be the same as A): ");
                scanf("%d %d", &rows_b, &cols_b);

                if (rows_a == rows_b && cols_a == cols_b) {
                    printf("Enter elements of matrix B:\n");
                    input_matrix(b, rows_b, cols_b);
                    subtract_matrices(a, b, c, rows_a, cols_a);
                    printf("Resulting Matrix (A - B):\n");
                    print_matrix(c, rows_a, cols_a);
                } else {
                    printf("Matrix dimensions do not match for subtraction!\n");
                }
                break;

            case 3:
                printf("Enter number of rows and columns for matrix A: ");
                scanf("%d %d", &rows_a, &cols_a);
                printf("Enter elements of matrix A:\n");
                input_matrix(a, rows_a, cols_a);

                printf("Enter number of rows and columns for matrix B (columns of A should equal rows of B): ");
                scanf("%d %d", &rows_b, &cols_b);

                if (cols_a == rows_b) {
                    printf("Enter elements of matrix B:\n");
                    input_matrix(b, rows_b, cols_b);
                    multiply_matrices(a, b, c, rows_a, cols_a, rows_b, cols_b);
                    printf("Resulting Matrix (A * B):\n");
                    print_matrix(c, rows_a, cols_b);
                } else {
                    printf("Matrix dimensions do not match for multiplication!\n");
                }
                break;

            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void input_matrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract_matrices(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiply_matrices(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows_a, int cols_a, int rows_b, int cols_b) {
    for (int i = 0; i < rows_a; ++i) {
        for (int j = 0; j < cols_b; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < cols_a; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}