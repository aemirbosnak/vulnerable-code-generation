//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

void readMatrix(Matrix *m) {
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m->rows, &m->cols);
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            scanf("%d", &m->data[i][j]);
        }
    }
}

void displayMatrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(const Matrix *a, const Matrix *b, Matrix *result) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: Matrices must have the same dimensions for addition.\n");
        exit(EXIT_FAILURE);
    }
    
    result->rows = a->rows;
    result->cols = a->cols;
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void subtractMatrices(const Matrix *a, const Matrix *b, Matrix *result) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: Matrices must have the same dimensions for subtraction.\n");
        exit(EXIT_FAILURE);
    }
    
    result->rows = a->rows;
    result->cols = a->cols;
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
}

void multiplyMatrices(const Matrix *a, const Matrix *b, Matrix *result) {
    if (a->cols != b->rows) {
        printf("Error: Number of columns of the first matrix must match the number of rows of the second.\n");
        exit(EXIT_FAILURE);
    }
    
    result->rows = a->rows;
    result->cols = b->cols;
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
}

int main() {
    Matrix matrixA, matrixB, result;
    int choice;
    
    printf("Welcome to the Matrix Operations Program!\n");
    
    // Input first matrix
    printf("Matrix A:\n");
    readMatrix(&matrixA);
    
    // Input second matrix
    printf("Matrix B:\n");
    readMatrix(&matrixB);
    
    do {
        printf("\nChoose an operation:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Display Matrices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMatrices(&matrixA, &matrixB, &result);
                printf("Result of A + B:\n");
                displayMatrix(&result);
                break;
            case 2:
                subtractMatrices(&matrixA, &matrixB, &result);
                printf("Result of A - B:\n");
                displayMatrix(&result);
                break;
            case 3:
                multiplyMatrices(&matrixA, &matrixB, &result);
                printf("Result of A * B:\n");
                displayMatrix(&result);
                break;
            case 4:
                printf("Matrix A:\n");
                displayMatrix(&matrixA);
                printf("Matrix B:\n");
                displayMatrix(&matrixB);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}