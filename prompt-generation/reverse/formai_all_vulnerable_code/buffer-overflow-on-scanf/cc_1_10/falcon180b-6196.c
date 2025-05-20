//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void create_matrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    printf("Enter matrix elements:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<cols; i++) {
        for(j=0; j<rows; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

void add_matrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            matrix1[i][j] += matrix2[i][j];
        }
    }
}

void subtract_matrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            matrix1[i][j] -= matrix2[i][j];
        }
    }
}

void multiply_matrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;
    for(i=0; i<rows1; i++) {
        for(j=0; j<cols2; j++) {
            result[i][j] = 0;
            for(k=0; k<cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX], rows1, cols1, rows2, cols2;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    create_matrix(matrix1, rows1, cols1);
    create_matrix(matrix2, rows2, cols2);
    if(cols1 == rows2) {
        multiply_matrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
        printf("Product of matrices:\n");
        print_matrix(result, rows1, cols2);
    } else {
        printf("Matrices cannot be multiplied.\n");
    }
    return 0;
}