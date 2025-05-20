//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int rows;
    int cols;
    int matrix[MAX_SIZE][MAX_SIZE];
} Matrix;

void printMatrix(Matrix m);
Matrix addMatrices(Matrix m1, Matrix m2);
Matrix subtractMatrices(Matrix m1, Matrix m2);
Matrix multiplyMatrices(Matrix m1, Matrix m2);
Matrix transposeMatrix(Matrix m);
void initializeMatrix(Matrix *m, int rows, int cols);
void inputMatrix(Matrix *m);

void loveAndMatrices(void);

int main() {
    // Our Play begins here
    loveAndMatrices();
    return 0;
}

void loveAndMatrices(void) {
    Matrix M1, M2, result;
    char choice;

    printf("Enter the rows and columns for the first matrix (max %d for both): ", MAX_SIZE);
    int r1, c1;
    scanf("%d %d", &r1, &c1);
    initializeMatrix(&M1, r1, c1);
    inputMatrix(&M1);

    printf("Enter the rows and columns for the second matrix (max %d for both): ", MAX_SIZE);
    int r2, c2;
    scanf("%d %d", &r2, &c2);
    initializeMatrix(&M2, r2, c2);
    inputMatrix(&M2);

    // The problems of our tragic lovers begin
    printf("What would you like to do in this tale of matrices?\n");
    printf("1. Add the matrices (M1 + M2)\n");
    printf("2. Subtract the matrices (M1 - M2)\n");
    printf("3. Multiply the matrices (M1 * M2)\n");
    printf("4. Transpose the first matrix (M1^T)\n");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            if (M1.rows == M2.rows && M1.cols == M2.cols) {
                result = addMatrices(M1, M2);
                printf("The sum of ingrate hearts:\n");
                printMatrix(result);
            } else {
                printf("Alas, the matrices cannot be added!\n");
            }
            break;
        case '2':
            if (M1.rows == M2.rows && M1.cols == M2.cols) {
                result = subtractMatrices(M1, M2);
                printf("The anguish of subtraction, a love lost:\n");
                printMatrix(result);
            } else {
                printf("Alas, the matrices cannot be subtracted!\n");
            }
            break;
        case '3':
            if (M1.cols == M2.rows) {
                result = multiplyMatrices(M1, M2);
                printf("The product of their fateful love:\n");
                printMatrix(result);
            } else {
                printf("Alas, the matrices cannot be multiplied!\n");
            }
            break;
        case '4':
            result = transposeMatrix(M1);
            printf("The transposed essence of their love:\n");
            printMatrix(result);
            break;
        default:
            printf("A tale of choices, yet you chose none!\n");
    }
}

void printMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.matrix[i][j]);
        }
        printf("\n");
    }
}

Matrix addMatrices(Matrix m1, Matrix m2) {
    Matrix result;
    initializeMatrix(&result, m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }
    return result;
}

Matrix subtractMatrices(Matrix m1, Matrix m2) {
    Matrix result;
    initializeMatrix(&result, m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
        }
    }
    return result;
}

Matrix multiplyMatrices(Matrix m1, Matrix m2) {
    Matrix result;
    initializeMatrix(&result, m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < m1.cols; k++) {
                result.matrix[i][j] += (m1.matrix[i][k] * m2.matrix[k][j]);
            }
        }
    }
    return result;
}

Matrix transposeMatrix(Matrix m) {
    Matrix result;
    initializeMatrix(&result, m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.matrix[j][i] = m.matrix[i][j];
        }
    }
    return result;
}

void initializeMatrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
}

void inputMatrix(Matrix *m) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            scanf("%d", &m->matrix[i][j]);
        }
    }
}