//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void allocate_matrix(int ***matrix, int rows, int cols);
void deallocate_matrix(int **matrix, int rows);
void input_matrix(int **matrix, int rows, int cols);
void print_matrix(int **matrix, int rows, int cols);
void add_matrices(int **matA, int **matB, int **result, int rows, int cols);
void subtract_matrices(int **matA, int **matB, int **result, int rows, int cols);
void multiply_matrices(int **matA, int **matB, int **result, int rowsA, int colsA, int rowsB, int colsB);
void transpose_matrix(int **matrix, int **result, int rows, int cols);
void menu();

int main() {
    menu();
    return 0;
}

// Function to display the menu
void menu() {
    int choice;
    int rowsA, colsA, rowsB, colsB;
    int **matA, **matB, **result;

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter dimensions of Matrix A (rows columns): ");
                scanf("%d %d", &rowsA, &colsA);
                allocate_matrix(&matA, rowsA, colsA);
                input_matrix(matA, rowsA, colsA);

                printf("Enter dimensions of Matrix B (rows columns): ");
                scanf("%d %d", &rowsB, &colsB);
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Matrix sizes do not match for addition!\n");
                    deallocate_matrix(matA, rowsA);
                    break;
                }
                allocate_matrix(&matB, rowsB, colsB);
                input_matrix(matB, rowsB, colsB);
                allocate_matrix(&result, rowsA, colsA);

                add_matrices(matA, matB, result, rowsA, colsA);
                printf("Result of Addition:\n");
                print_matrix(result, rowsA, colsA);

                deallocate_matrix(matA, rowsA);
                deallocate_matrix(matB, rowsB);
                deallocate_matrix(result, rowsA);
                break;

            case 2:
                printf("Enter dimensions of Matrix A (rows columns): ");
                scanf("%d %d", &rowsA, &colsA);
                allocate_matrix(&matA, rowsA, colsA);
                input_matrix(matA, rowsA, colsA);

                printf("Enter dimensions of Matrix B (rows columns): ");
                scanf("%d %d", &rowsB, &colsB);
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Matrix sizes do not match for subtraction!\n");
                    deallocate_matrix(matA, rowsA);
                    break;
                }
                allocate_matrix(&matB, rowsB, colsB);
                input_matrix(matB, rowsB, colsB);
                allocate_matrix(&result, rowsA, colsA);

                subtract_matrices(matA, matB, result, rowsA, colsA);
                printf("Result of Subtraction:\n");
                print_matrix(result, rowsA, colsA);

                deallocate_matrix(matA, rowsA);
                deallocate_matrix(matB, rowsB);
                deallocate_matrix(result, rowsA);
                break;

            case 3:
                printf("Enter dimensions for Matrix A (rows columns): ");
                scanf("%d %d", &rowsA, &colsA);
                allocate_matrix(&matA, rowsA, colsA);
                input_matrix(matA, rowsA, colsA);

                printf("Enter dimensions for Matrix B (rows columns): ");
                scanf("%d %d", &rowsB, &colsB);
                if (colsA != rowsB) {
                    printf("Matrix sizes do not match for multiplication!\n");
                    deallocate_matrix(matA, rowsA);
                    break;
                }
                allocate_matrix(&matB, rowsB, colsB);
                input_matrix(matB, rowsB, colsB);
                allocate_matrix(&result, rowsA, colsB);

                multiply_matrices(matA, matB, result, rowsA, colsA, rowsB, colsB);
                printf("Result of Multiplication:\n");
                print_matrix(result, rowsA, colsB);

                deallocate_matrix(matA, rowsA);
                deallocate_matrix(matB, rowsB);
                deallocate_matrix(result, rowsA);
                break;

            case 4:
                printf("Enter dimensions of Matrix (rows columns): ");
                scanf("%d %d", &rowsA, &colsA);
                allocate_matrix(&matA, rowsA, colsA);
                input_matrix(matA, rowsA, colsA);
                allocate_matrix(&result, colsA, rowsA);

                transpose_matrix(matA, result, rowsA, colsA);
                printf("Result of Transposition:\n");
                print_matrix(result, colsA, rowsA);

                deallocate_matrix(matA, rowsA);
                deallocate_matrix(result, colsA);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option! Please select between 1-5.\n");
        }
    } while (choice != 5);
}

// Function to allocate memory for a matrix
void allocate_matrix(int ***matrix, int rows, int cols) {
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
    }
}

// Function to deallocate memory for a matrix
void deallocate_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to input matrix elements
void input_matrix(int **matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int **matA, int **matB, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int **matA, int **matB, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int **matA, int **matB, int **result, int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize to 0
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(int **matrix, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}