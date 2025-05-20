//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Structure to define a Matrix
typedef struct {
    int rows;
    int cols;
    int data[MAX][MAX];
} Matrix;

// Function prototypes
void inputMatrix(Matrix *m);
void displayMatrix(const Matrix *m);
Matrix addMatrices(const Matrix *m1, const Matrix *m2);
Matrix multiplyMatrices(const Matrix *m1, const Matrix *m2);
int isSquareMatrix(const Matrix *m);
int determinant(const Matrix *m);
void transposeMatrix(const Matrix *m, Matrix *result);
void clearScreen();

int main() {
    Matrix m1, m2, result;
    int choice, det;

    do {
        clearScreen();
        printf("Matrix Operations Menu:\n");
        printf("1. Input First Matrix\n");
        printf("2. Input Second Matrix\n");
        printf("3. Display First Matrix\n");
        printf("4. Display Second Matrix\n");
        printf("5. Add Matrices\n");
        printf("6. Multiply Matrices\n");
        printf("7. Transpose First Matrix\n");
        printf("8. Determinant of First Matrix\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the First Matrix:\n");
                inputMatrix(&m1);
                break;
            case 2:
                printf("Enter the Second Matrix:\n");
                inputMatrix(&m2);
                break;
            case 3:
                printf("First Matrix:\n");
                displayMatrix(&m1);
                break;
            case 4:
                printf("Second Matrix:\n");
                displayMatrix(&m2);
                break;
            case 5:
                if (m1.rows == m2.rows && m1.cols == m2.cols) {
                    result = addMatrices(&m1, &m2);
                    printf("Result of Addition:\n");
                    displayMatrix(&result);
                } else {
                    printf("Matrices must be of same dimensions for addition!\n");
                }
                break;
            case 6:
                if (m1.cols == m2.rows) {
                    result = multiplyMatrices(&m1, &m2);
                    printf("Result of Multiplication:\n");
                    displayMatrix(&result);
                } else {
                    printf("Number of columns in first matrix must equal number of rows in second!\n");
                }
                break;
            case 7:
                transposeMatrix(&m1, &result);
                printf("Transpose of First Matrix:\n");
                displayMatrix(&result);
                break;
            case 8:
                if (isSquareMatrix(&m1)) {
                    det = determinant(&m1);
                    printf("Determinant of First Matrix: %d\n", det);
                } else {
                    printf("Determinant can only be calculated for square matrices.\n");
                }
                break;
            case 9:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }

        // Pause before next operation
        printf("Press Enter to continue...");
        while(getchar() != '\n'); // clear the buffer
        getchar();

    } while (choice != 9);

    return 0;
}

void inputMatrix(Matrix *m) {
    printf("Enter number of rows and columns (max %d): ", MAX);
    scanf("%d %d", &m->rows, &m->cols);
    
    printf("Enter the elements:\n");
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

Matrix addMatrices(const Matrix *m1, const Matrix *m2) {
    Matrix result;
    result.rows = m1->rows;
    result.cols = m1->cols;

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result.data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return result;
}

Matrix multiplyMatrices(const Matrix *m1, const Matrix *m2) {
    Matrix result;
    result.rows = m1->rows;
    result.cols = m2->cols;

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1->cols; k++) {
                result.data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return result;
}

int isSquareMatrix(const Matrix *m) {
    return m->rows == m->cols;
}

int determinant(const Matrix *m) {
    if (m->rows == 1) {
        return m->data[0][0];
    }
    if (m->rows == 2) {
        return m->data[0][0] * m->data[1][1] - m->data[0][1] * m->data[1][0];
    }
    
    int det = 0;
    for (int p = 0; p < m->cols; p++) {
        Matrix subMatrix;
        subMatrix.rows = m->rows - 1;
        subMatrix.cols = m->cols - 1;

        for (int i = 1; i < m->rows; i++) {
            int colIndex = 0;
            for (int j = 0; j < m->cols; j++) {
                if (j == p) continue;
                subMatrix.data[i - 1][colIndex++] = m->data[i][j];
            }
        }
        det += (p % 2 == 0 ? 1 : -1) * m->data[0][p] * determinant(&subMatrix);
    }
    return det;
}

void transposeMatrix(const Matrix *m, Matrix *result) {
    result->rows = m->cols;
    result->cols = m->rows;

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result->data[j][i] = m->data[i][j];
        }
    }
}

void clearScreen() {
    printf("\033[H\033[J");  // ANSI escape code to clear the screen
}