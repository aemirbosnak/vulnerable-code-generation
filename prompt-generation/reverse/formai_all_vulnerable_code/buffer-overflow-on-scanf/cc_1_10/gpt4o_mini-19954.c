//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

void inputMatrix(Matrix *m) {
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m->rows, &m->cols);
    printf("Enter elements of the matrix:\n");
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

Matrix addMatrices(const Matrix *a, const Matrix *b) {
    Matrix result;
    result.rows = a->rows;
    result.cols = a->cols;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

Matrix subtractMatrices(const Matrix *a, const Matrix *b) {
    Matrix result;
    result.rows = a->rows;
    result.cols = a->cols;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return result;
}

Matrix multiplyMatrices(const Matrix *a, const Matrix *b) {
    Matrix result;
    result.rows = a->rows;
    result.cols = b->cols;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

Matrix transposeMatrix(const Matrix *m) {
    Matrix result;
    result.rows = m->cols;
    result.cols = m->rows;

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result.data[j][i] = m->data[i][j];
        }
    }
    return result;
}

void menu() {
    printf("\nMatrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("4. Transpose Matrix\n");
    printf("5. Exit\n");
}

int main() {
    Matrix a, b, result;
    int option;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Input Matrix A:\n");
                inputMatrix(&a);
                printf("Input Matrix B:\n");
                inputMatrix(&b);
                
                if (a.rows != b.rows || a.cols != b.cols) {
                    printf("Error: Matrices must have the same dimensions to add.\n");
                    break;
                }
                
                result = addMatrices(&a, &b);
                printf("Result of Matrix A + Matrix B:\n");
                displayMatrix(&result);
                break;

            case 2:
                printf("Input Matrix A:\n");
                inputMatrix(&a);
                printf("Input Matrix B:\n");
                inputMatrix(&b);
                
                if (a.rows != b.rows || a.cols != b.cols) {
                    printf("Error: Matrices must have the same dimensions to subtract.\n");
                    break;
                }
                
                result = subtractMatrices(&a, &b);
                printf("Result of Matrix A - Matrix B:\n");
                displayMatrix(&result);
                break;

            case 3:
                printf("Input Matrix A:\n");
                inputMatrix(&a);
                printf("Input Matrix B:\n");
                inputMatrix(&b);
                
                if (a.cols != b.rows) {
                    printf("Error: Number of columns in Matrix A must equal number of rows in Matrix B.\n");
                    break;
                }
                
                result = multiplyMatrices(&a, &b);
                printf("Result of Matrix A * Matrix B:\n");
                displayMatrix(&result);
                break;

            case 4:
                printf("Input Matrix:\n");
                inputMatrix(&a);
                result = transposeMatrix(&a);
                printf("Transpose of the Matrix:\n");
                displayMatrix(&result);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}