//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int rows;
    int cols;
    double data[MAX_SIZE][MAX_SIZE];
} Matrix;

// Function prototypes
Matrix createMatrix(int rows, int cols);
void fillMatrix(Matrix* m);
void printMatrix(const Matrix* m);
Matrix addMatrices(const Matrix* m1, const Matrix* m2);
Matrix multiplyMatrices(const Matrix* m1, const Matrix* m2);
Matrix transposeMatrix(const Matrix* m);
void freeMatrix(Matrix* m);

// Main function
int main() {
    Matrix m1 = createMatrix(3, 3);
    Matrix m2 = createMatrix(3, 3);
    
    printf("Filling matrix 1:\n");
    fillMatrix(&m1);
    
    printf("Filling matrix 2:\n");
    fillMatrix(&m2);
    
    printf("Matrix 1:\n");
    printMatrix(&m1);
    
    printf("Matrix 2:\n");
    printMatrix(&m2);

    Matrix sum = addMatrices(&m1, &m2);
    printf("Sum of matrices:\n");
    printMatrix(&sum);
    freeMatrix(&sum);
    
    Matrix product = multiplyMatrices(&m1, &m2);
    printf("Product of matrices:\n");
    printMatrix(&product);
    freeMatrix(&product);
    
    Matrix transposed = transposeMatrix(&m1);
    printf("Transposed matrix 1:\n");
    printMatrix(&transposed);
    freeMatrix(&transposed);
    
    freeMatrix(&m1);
    freeMatrix(&m2);
    
    return 0;
}

// Function to create a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    return m;
}

// Function to fill the matrix
void fillMatrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Enter value for element [%d][%d]: ", i, j);
            scanf("%lf", &m->data[i][j]);
        }
    }
}

// Function to print matrix
void printMatrix(const Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%0.2lf ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix addMatrices(const Matrix* m1, const Matrix* m2) {
    Matrix result = createMatrix(m1->rows, m1->cols);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result.data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(const Matrix* m1, const Matrix* m2) {
    if (m1->cols != m2->rows) {
        fprintf(stderr, "Error: Cannot multiply matrices, incompatible dimensions.\n");
        exit(EXIT_FAILURE);
    }
    Matrix result = createMatrix(m1->rows, m2->cols);
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1->cols; k++) {
                result.data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix transposeMatrix(const Matrix* m) {
    Matrix result = createMatrix(m->cols, m->rows);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result.data[j][i] = m->data[i][j];
        }
    }
    return result;
}

// Function to "deallocate" matrix (No dynamic memory used)
void freeMatrix(Matrix* m) {
    // Nothing to free in this implementation, just a placeholder
    // if dynamic memory allocation is ever used, free it here
    m->rows = 0;
    m->cols = 0;
}