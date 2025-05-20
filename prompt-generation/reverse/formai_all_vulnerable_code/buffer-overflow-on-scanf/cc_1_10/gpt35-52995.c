//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>

//Function to perform matrix addition
void matrix_add(int a[10][10], int b[10][10], int c[10][10], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

//Function to perform matrix multiplication
void matrix_multiply(int a[10][10], int b[10][10], int c[10][10], int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;

    if(cols1 != rows2) {
        printf("Error: The matrices cannot be multiplied\n");
        return;
    }

    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            c[i][j] = 0;
            for(k = 0; k < cols1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

//Function to display a matrix
void display(int a[10][10], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[10][10], b[10][10], c[10][10];
    int rows1, cols1, rows2, cols2;
    int i, j;

    //Get the dimensions for Matrix A
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rows1, &cols1);

    //Get the elements for Matrix A
    printf("Enter the elements of Matrix A:\n");
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    //Get the dimensions for Matrix B
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rows2, &cols2);

    //Get the elements for Matrix B
    printf("Enter the elements of Matrix B:\n");
    for(i = 0; i < rows2; i++) {
        for(j = 0; j < cols2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    //Perform Matrix Addition
    printf("Matrix Addition:\n");
    matrix_add(a, b, c, rows1, cols1);
    display(c, rows1, cols1);

    //Perform Matrix Multiplication
    printf("Matrix Multiplication:\n");
    matrix_multiply(a, b, c, rows1, cols1, rows2, cols2);
    display(c, rows1, cols2);

    return 0;
}