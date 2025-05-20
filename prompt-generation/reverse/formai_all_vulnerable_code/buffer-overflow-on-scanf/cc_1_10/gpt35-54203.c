//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void create_matrix(int matrix[][MAX_COLS], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter value for row %d, column %d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Matrix created successfully!\n");
}

void display_matrix(int matrix[][MAX_COLS], int rows, int cols) {
    printf("Matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int matrix1[][MAX_COLS], int rows1, int cols1, int matrix2[][MAX_COLS], int rows2, int cols2, int result[][MAX_COLS]) {
    if(cols1 != rows2) {
        printf("Error: Invalid matrix dimensions for multiplication!\n");
        return;
    }
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2;
    printf("Enter dimensions of matrix 1: ");
    scanf("%d%d", &rows1, &cols1);
    printf("Enter dimensions of matrix 2: ");
    scanf("%d%d", &rows2, &cols2);
    if(cols1 != rows2) {
        printf("Error: Invalid matrix dimensions for multiplication!\n");
        return 0;
    }
    printf("Creating matrix 1...\n");
    create_matrix(matrix1, rows1, cols1);
    display_matrix(matrix1, rows1, cols1);
    printf("Creating matrix 2...\n");
    create_matrix(matrix2, rows2, cols2);
    display_matrix(matrix2, rows2, cols2);
    printf("Multiplying matrices...\n");
    multiply_matrices(matrix1, rows1, cols1, matrix2, rows2, cols2, result);
    display_matrix(result, rows1, cols2);
    return 0;
}