//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>

// function to display matrix
void display(int matrix[][3], int rows) {
    printf("The matrix is:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
void addMatrix(int matrix1[][3], int matrix2[][3], int rows) {
    int sum[rows][3];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("The sum of the two matrices is:\n");
    display(sum, rows);
}

// function to multiply two matrices
void multiplyMatrix(int matrix1[][3], int matrix2[][3], int rows) {
    int product[rows][3];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            product[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("The product of the two matrices is:\n");
    display(product, rows);
}

int main() {
    int rows;
    printf("Enter the number of rows for the matrix: ");
    scanf("%d", &rows);
    int matrix1[rows][3], matrix2[rows][3];
    printf("Enter the values of first matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the values of second matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    display(matrix1, rows);
    display(matrix2, rows);
    addMatrix(matrix1, matrix2, rows);
    multiplyMatrix(matrix1, matrix2, rows);
    return 0;
}