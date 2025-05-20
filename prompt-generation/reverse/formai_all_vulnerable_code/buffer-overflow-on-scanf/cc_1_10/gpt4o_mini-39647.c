//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIM 5
#define MAX_VAL 50

void fillMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols);
void printMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols);
void addMatrices(int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM], int rows, int cols);
void multiplyMatrices(int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX_DIM][MAX_DIM], int transposed[MAX_DIM][MAX_DIM], int rows, int cols);
void surrealMatrixTransform(int matrix[MAX_DIM][MAX_DIM], int rows, int cols);

int main() {
    srand(time(NULL));

    int matrix1[MAX_DIM][MAX_DIM], matrix2[MAX_DIM][MAX_DIM], sum[MAX_DIM][MAX_DIM], product[MAX_DIM][MAX_DIM], transposed[MAX_DIM][MAX_DIM];

    int rows1, cols1, rows2, cols2;

    printf("In the land of matrices, where numbers dance:\n");
    printf("Enter the dimensions of the first matrix (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter the dimensions of the second matrix (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);

    if(cols1 != rows2) {
        printf("The spark of multiplication fizzles – dimensions do not align!\n");
        return 1;
    }

    fillMatrix(matrix1, rows1, cols1);
    fillMatrix(matrix2, rows2, cols2);

    printf("Matrix 1, a cloud of fluttering butterflies:\n");
    printMatrix(matrix1, rows1, cols1);

    printf("Matrix 2, a river of twisting reflections:\n");
    printMatrix(matrix2, rows2, cols2);

    addMatrices(matrix1, matrix1, sum, rows1, cols1);
    printf("Sum of Matrix 1 with itself, a swirling vortex:\n");
    printMatrix(sum, rows1, cols1);

    multiplyMatrices(matrix1, matrix2, product, rows1, cols1, cols2);
    printf("Product of Matrix 1 and Matrix 2, a kaleidoscope of numbers:\n");
    printMatrix(product, rows1, cols2);

    transposeMatrix(matrix1, transposed, rows1, cols1);
    printf("Transposed Matrix 1, a veil lifted, revealing secrets:\n");
    printMatrix(transposed, cols1, rows1);

    surrealMatrixTransform(matrix1, rows1, cols1);
    printf("Matrix 1 transformed into the surreal realm:\n");
    printMatrix(matrix1, rows1, cols1);

    return 0;
}

void fillMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % MAX_VAL;
        }
    }
}

void printMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_DIM][MAX_DIM], int mat2[MAX_DIM][MAX_DIM], int result[MAX_DIM][MAX_DIM], int rows1, int cols1, int cols2) {
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_DIM][MAX_DIM], int transposed[MAX_DIM][MAX_DIM], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void surrealMatrixTransform(int matrix[MAX_DIM][MAX_DIM], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 == 0) {
                matrix[i][j] = (matrix[i][j] * matrix[i][j]) % MAX_VAL;
            } else {
                matrix[i][j] = (matrix[i][j] * 3 + 1) % MAX_VAL;
            }
        }
    }
}