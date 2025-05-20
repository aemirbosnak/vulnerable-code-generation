//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    int data[MAX_ROWS][MAX_COLS];
} Matrix;

// Function to create a matrix with given dimensions
Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    return m;
}

// Function to input matrix elements
void inputMatrix(Matrix* m) {
    printf("Enter the elements of the matrix (%d x %d):\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m->data[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(Matrix m) {
    printf("Matrix (%d x %d):\n", m.rows, m.cols);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix addMatrices(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "Error: Matrices dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }
    
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        fprintf(stderr, "Error: Matrices dimensions do not match for multiplication.\n");
        exit(EXIT_FAILURE);
    }
    
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix transposeMatrix(Matrix m) {
    Matrix result = createMatrix(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[j][i] = m.data[i][j];
        }
    }
    return result;
}

// Wizard-like function to guide user through operations on matrices
void matrixOperationsWizard() {
    printf("Welcome to the Matrix Operations Wizard!\n");
    int choice;
    
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("3. Transpose\n");
    scanf("%d", &choice);

    int r1, c1, r2, c2;
    Matrix mat1, mat2, result;

    switch (choice) {
        case 1: // Addition
            printf("Enter the number of rows and columns for the matrices:\n");
            scanf("%d %d", &r1, &c1);
            mat1 = createMatrix(r1, c1);
            inputMatrix(&mat1);
            mat2 = createMatrix(r1, c1);
            inputMatrix(&mat2);
            result = addMatrices(mat1, mat2);
            printMatrix(result);
            break;
        
        case 2: // Multiplication
            printf("Enter dimensions for the first matrix (rows columns):\n");
            scanf("%d %d", &r1, &c1);
            mat1 = createMatrix(r1, c1);
            inputMatrix(&mat1);
            printf("Enter dimensions for the second matrix (rows columns):\n");
            scanf("%d %d", &r2, &c2);
            mat2 = createMatrix(r2, c2);
            inputMatrix(&mat2);
            result = multiplyMatrices(mat1, mat2);
            printMatrix(result);
            break;

        case 3: // Transpose
            printf("Enter dimensions for the matrix to transpose (rows columns):\n");
            scanf("%d %d", &r1, &c1);
            mat1 = createMatrix(r1, c1);
            inputMatrix(&mat1);
            result = transposeMatrix(mat1);
            printMatrix(result);
            break;

        default:
            fprintf(stderr, "Invalid choice! Please try again.\n");
    }
}

int main() {
    matrixOperationsWizard();
    return 0;
}