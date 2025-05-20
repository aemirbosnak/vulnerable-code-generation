//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void create_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int rows, int cols, int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract_matrices(int rows, int cols, int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2, option;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1!= rows2) {
        printf("Error: The number of columns in the first matrix must match the number of rows in the second matrix.\n");
        return 1;
    }

    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

    create_matrix(rows1, cols1, matrix1);
    create_matrix(rows2, cols2, matrix2);

    printf("The first matrix:\n");
    print_matrix(rows1, cols1, matrix1);
    printf("\nThe second matrix:\n");
    print_matrix(rows2, cols2, matrix2);

    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            add_matrices(rows1, cols1, matrix1, matrix2, result);
            printf("\nThe result of matrix addition:\n");
            print_matrix(rows1, cols1, result);
            break;
        case 2:
            subtract_matrices(rows1, cols1, matrix1, matrix2, result);
            printf("\nThe result of matrix subtraction:\n");
            print_matrix(rows1, cols1, result);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}