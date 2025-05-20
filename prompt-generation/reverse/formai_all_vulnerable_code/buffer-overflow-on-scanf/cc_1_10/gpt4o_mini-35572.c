//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Structure to hold a Matrix
typedef struct {
    int rows;
    int cols;
    float data[MAX][MAX];
} Matrix;

// Function Declarations
Matrix createMatrix(int rows, int cols);
void printMatrix(Matrix mat);
Matrix addMatrices(Matrix mat1, Matrix mat2);
Matrix multiplyMatrices(Matrix mat1, Matrix mat2);
Matrix transposeMatrix(Matrix mat);
float determinantMatrix(Matrix mat);
Matrix inverseMatrix(Matrix mat);

// Main function
int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns for Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    // Check for valid dimensions for addition
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices must have the same dimensions for addition.\n");
        return -1;
    }

    // Create two matrices
    Matrix mat1 = createMatrix(rows1, cols1);
    Matrix mat2 = createMatrix(rows2, cols2);

    // Addition of Matrices
    Matrix sum = addMatrices(mat1, mat2);
    printf("Sum of Matrix 1 and Matrix 2:\n");
    printMatrix(sum);
    
    // Check for valid dimensions for multiplication
    if (cols1 != rows2) {
        printf("Matrices must have compatible dimensions for multiplication.\n");
        return -1;
    }

    // Multiplication of Matrices
    Matrix product = multiplyMatrices(mat1, mat2);
    printf("Product of Matrix 1 and Matrix 2:\n");
    printMatrix(product);

    // Transpose of Matrix 1
    Matrix transposed = transposeMatrix(mat1);
    printf("Transpose of Matrix 1:\n");
    printMatrix(transposed);

    // Determinant of a square matrix
    if (rows1 == cols1) {
        float det = determinantMatrix(mat1);
        printf("Determinant of Matrix 1: %f\n", det);
    } else {
        printf("Determinant can only be calculated for a square matrix.\n");
    }

    // Inverse of a square matrix
    if (rows1 == cols1) {
        Matrix inv = inverseMatrix(mat1);
        printf("Inverse of Matrix 1:\n");
        printMatrix(inv);
    } else {
        printf("Inverse can only be calculated for a square matrix.\n");
    }

    return 0;
}

// Function to create a matrix and input values
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%f", &mat.data[i][j]);
        }
    }
    return mat;
}

// Function to print a matrix
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%0.2f ", mat.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix addMatrices(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(Matrix mat1, Matrix mat2) {
    Matrix result = createMatrix(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < mat1.cols; k++) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix transposeMatrix(Matrix mat) {
    Matrix result = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            result.data[j][i] = mat.data[i][j];
        }
    }
    return result;
}

// Function to compute the determinant of a matrix
float determinantMatrix(Matrix mat) {
    if (mat.rows == 1) {
        return mat.data[0][0];
    } else if (mat.rows == 2) {
        return mat.data[0][0] * mat.data[1][1] - mat.data[0][1] * mat.data[1][0];
    } else {
        float det = 0;
        for (int p = 0; p < mat.cols; p++) {
            Matrix subMat = createMatrix(mat.rows - 1, mat.cols - 1);
            for (int i = 1; i < mat.rows; i++) {
                for (int j = 0, subCol = 0; j < mat.cols; j++) {
                    if (j == p) continue;
                    subMat.data[i - 1][subCol++] = mat.data[i][j];
                }
            }
            det += (p % 2 == 0 ? 1 : -1) * mat.data[0][p] * determinantMatrix(subMat);
        }
        return det;
    }
}

// Function to compute the inverse of a matrix
Matrix inverseMatrix(Matrix mat) {
    Matrix inv;
    float det = determinantMatrix(mat);
    if (det == 0) {
        printf("Matrix is singular, cannot find its inverse.\n");
        inv.rows = 0;
        return inv;
    }

    // Calculate the inverse using adjugate method 
    inv = createMatrix(mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            // Minor matrix
            Matrix subMat = createMatrix(mat.rows - 1, mat.cols - 1);
            for (int x = 0, subRow = 0; x < mat.rows; x++) {
                for (int y = 0, subCol = 0; y < mat.cols; y++) {
                    if (x != i && y != j) {
                        subMat.data[subRow][subCol++] = mat.data[x][y];
                        if (subCol == subMat.cols) {
                            subRow++;
                            subCol = 0;
                        }
                    }
                }
            }
            inv.data[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * determinantMatrix(subMat) / det;
        }
    }

    return inv;
}