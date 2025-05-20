//FormAI DATASET v1.0 Category: Matrix operations ; Style: bold
#include <stdio.h>

// function to perform matrix addition
void add_matrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// function to perform matrix multiplication
void multiply_matrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// function to display a matrix
void display_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1 = 3, cols1 = 3, rows2 = 3, cols2 = 3;
    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols1];
    
    // get input for matrix1
    printf("Enter elements of matrix1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    // get input for matrix2
    printf("Enter elements of matrix2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // perform addition
    add_matrices(rows1, cols1, matrix1, matrix2, result);
    printf("The sum of the matrices is:\n");
    display_matrix(rows1, cols1, result);
    
    // perform multiplication
    multiply_matrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
    printf("The product of the matrices is:\n");
    display_matrix(rows1, cols2, result);
    
    return 0;
}