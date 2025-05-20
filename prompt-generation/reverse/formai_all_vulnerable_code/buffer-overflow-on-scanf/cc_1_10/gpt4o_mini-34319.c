//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrix(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrix(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int firstRows, int firstCols, int secondCols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void getCofactor(int matrix[MAX_SIZE][MAX_SIZE], int temp[MAX_SIZE][MAX_SIZE], int p, int q, int n);
int determinant(int matrix[MAX_SIZE][MAX_SIZE], int n);
void adjointMatrix(int matrix[MAX_SIZE][MAX_SIZE], int adj[MAX_SIZE][MAX_SIZE], int n);
int inverseMatrix(int matrix[MAX_SIZE][MAX_SIZE], float inverse[MAX_SIZE][MAX_SIZE], int n);

// Recursive function to perform operations on a matrix
void recursiveMatrixOperations(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    if (rows <= 0 || cols <= 0) return;

    // Transpose the matrix
    int transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrix, transposed, rows, cols);

    // Print original and transposed matrices
    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);
    printf("\nTransposed Matrix:\n");
    printMatrix(transposed, cols, rows);

    // Base case for determinant calculation
    if (rows == cols) {
        int det = determinant(matrix, rows);
        printf("\nDeterminant: %d\n", det);
    }
    
    // Recursive call with one less row and column
    recursiveMatrixOperations(matrix, rows - 1, cols - 1);
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE], rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        printf("Matrix size exceeds the maximum allowed size of %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the elements of the matrix:\n");
    inputMatrix(matrix, rows, cols);

    recursiveMatrixOperations(matrix, rows, cols);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void multiplyMatrix(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int firstRows, int firstCols, int secondCols) {
    for (int i = 0; i < firstRows; i++) {
        for (int j = 0; j < secondCols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < firstCols; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void getCofactor(int matrix[MAX_SIZE][MAX_SIZE], int temp[MAX_SIZE][MAX_SIZE], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    int temp[MAX_SIZE][MAX_SIZE]; 
    int sign = 1; 
    int det = 0; 
    for (int f = 0; f < n; f++) {
        getCofactor(matrix, temp, 0, f, n);
        det += sign * matrix[0][f] * determinant(temp, n - 1);
        sign = -sign; 
    }
    return det;
}

void adjointMatrix(int matrix[MAX_SIZE][MAX_SIZE], int adj[MAX_SIZE][MAX_SIZE], int n) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    int temp[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(matrix, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
}

int inverseMatrix(int matrix[MAX_SIZE][MAX_SIZE], float inverse[MAX_SIZE][MAX_SIZE], int n) {
    int det = determinant(matrix, n);
    if (det == 0) {
        printf("Singular matrix, can't find its inverse\n");
        return 0;
    }
    int adj[MAX_SIZE][MAX_SIZE];
    adjointMatrix(matrix, adj, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse[i][j] = adj[i][j] / (float)det;
    return 1;
}