//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>

// function to print the matrix
void print_matrix(int *matrix, int rows, int columns) {
    for(int i=0; i < rows; i++) {
        for(int j=0; j < columns; j++) {
            printf("%d ", *(matrix + i*columns + j));
        }
        printf("\n");
    }
    printf("\n");
}

// function to add two matrices
void add_matrices(int *matrix1, int *matrix2, int *result_matrix, int rows, int columns) {
    for(int i=0; i < rows; i++) {
        for(int j=0; j < columns; j++) {
            *(result_matrix + i*columns + j) = *(matrix1 + i*columns + j) + *(matrix2 + i*columns + j);
        }
    }
}

// function to subtract two matrices
void subtract_matrices(int *matrix1, int *matrix2, int *result_matrix, int rows, int columns) {
    for(int i=0; i < rows; i++) {
        for(int j=0; j < columns; j++) {
            *(result_matrix + i*columns + j) = *(matrix1 + i*columns + j) - *(matrix2 + i*columns + j);
        }
    }
}

// function to multiply two matrices
void multiply_matrices(int *matrix1, int *matrix2, int *result_matrix, int rows1, int columns1, int columns2) {
    for(int i=0; i < rows1; i++) {
        for(int j=0; j < columns2; j++) {
            *(result_matrix + i*columns2 + j) = 0;
            for(int k=0; k < columns1; k++) {
                *(result_matrix + i*columns2 + j) += *(matrix1 + i*columns1 + k) * *(matrix2 + k*columns2 + j);
            }
        }
    }
}

int main() {
    // inputting first matrix
    printf("Enter the dimensions of matrix 1:\n");
    int m1, n1;
    scanf("%d%d", &m1, &n1);
    int matrix1[m1][n1];
    printf("Enter the elements of matrix 1:\n");
    for(int i=0; i < m1; i++) {
        for(int j=0; j < n1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("The first matrix is:\n");
    print_matrix(&matrix1[0][0], m1, n1);
    
    // inputting second matrix
    printf("Enter the dimensions of matrix 2:\n");
    int m2, n2;
    scanf("%d%d", &m2, &n2);
    int matrix2[m2][n2];
    printf("Enter the elements of matrix 2:\n");
    for(int i=0; i < m2; i++) {
        for(int j=0; j < n2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("The second matrix is:\n");
    print_matrix(&matrix2[0][0], m2, n2);
    
    // adding the two matrices
    if(m1 == m2 && n1 == n2) {
        int sum_matrix[m1][n1];
        add_matrices(&matrix1[0][0], &matrix2[0][0], &sum_matrix[0][0], m1, n1);
        printf("The sum of the two matrices is:\n");
        print_matrix(&sum_matrix[0][0], m1, n1);
    }
    else {
        printf("Cannot add matrices of different dimensions.\n");
    }
    
    // subtracting the two matrices
    if(m1 == m2 && n1 == n2) {
        int diff_matrix[m1][n1];
        subtract_matrices(&matrix1[0][0], &matrix2[0][0], &diff_matrix[0][0], m1, n1);
        printf("The difference of the two matrices is:\n");
        print_matrix(&diff_matrix[0][0], m1, n1);
    }
    else {
        printf("Cannot subtract matrices of different dimensions.\n");
    }
    
    // multiplying the two matrices
    if(n1 == m2) {
        int product_matrix[m1][n2];
        multiply_matrices(&matrix1[0][0], &matrix2[0][0], &product_matrix[0][0], m1, n1, n2);
        printf("The product of the two matrices is:\n");
        print_matrix(&product_matrix[0][0], m1, n2);
    }
    else {
        printf("Cannot multiply matrices with incompatible dimensions.\n");
    }
    
    return 0;
}