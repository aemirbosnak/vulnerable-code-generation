//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void create_matrix(int mat[][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("Enter element for row %d and column %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void display_matrix(int mat[][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int mat1[][MAX], int mat2[][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            mat1[i][j] += mat2[i][j];
        }
    }
}

void subtract_matrices(int mat1[][MAX], int mat2[][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            mat1[i][j] -= mat2[i][j];
        }
    }
}

void multiply_matrices(int mat1[][MAX], int mat2[][MAX], int res[][MAX], int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;
    if(cols1!= rows2) {
        printf("Error: Invalid matrix dimensions for multiplication.\n");
        exit(1);
    }
    for(i=0; i<rows1; i++) {
        for(j=0; j<cols2; j++) {
            res[i][j] = 0;
            for(k=0; k<cols1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transpose_matrix(int mat[][MAX], int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            mat[j][i] = mat[i][j];
        }
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];
    int rows1, cols1, rows2, cols2;
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    if(cols1!= rows2) {
        printf("Error: Invalid matrix dimensions for multiplication.\n");
        exit(1);
    }
    create_matrix(mat1, rows1, cols1);
    create_matrix(mat2, rows2, cols2);
    display_matrix(mat1, rows1, cols1);
    display_matrix(mat2, rows2, cols2);
    multiply_matrices(mat1, mat2, res, rows1, cols1, rows2, cols2);
    display_matrix(res, rows1, cols2);
    transpose_matrix(mat1, rows1, cols1);
    display_matrix(mat1, rows1, cols1);
    return 0;
}