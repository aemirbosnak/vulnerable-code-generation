//FormAI DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function to print the matrix
void printMatrix(int** A, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** addMatrix(int** A, int** B, int rows, int cols) {
    int** C = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        C[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to subtract two matrices
int** subMatrix(int** A, int** B, int rows, int cols) {
    int** C = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        C[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Function to perform matrix multiplication
int** mulMatrix(int** A, int** B, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("\nThe matrices cannot be multiplied\n");
        exit(0);
    }
    int** C = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        C[i] = (int*)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    int rows, cols;
    
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &cols);
    
    int** A = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        A[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            printf("Enter the value for A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("\nEnter the number of rows for matrix B: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &cols);
    
    int** B = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        B[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            printf("Enter the value for B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    
    printf("\nMatrix A:\n");
    printMatrix(A, rows, cols);
    
    printf("\nMatrix B:\n");
    printMatrix(B, rows, cols);
    
    int** C = addMatrix(A, B, rows, cols);
    printf("\nAddition of matrices A and B:\n");
    printMatrix(C, rows, cols);
    
    C = subMatrix(A, B, rows, cols);
    printf("\nSubtraction of matrices A and B:\n");
    printMatrix(C, rows, cols);
    
    int rows2, cols2;
    printf("\nEnter the number of rows for matrix B: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &cols2);
    
    C = mulMatrix(A, B, rows, cols, rows2, cols2);
    printf("\nMultiplication of matrices A and B:\n");
    printMatrix(C, rows, cols2);
    
    // free the memory allocated for the matrices
    for (int i = 0; i < rows; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    
    return 0;
}