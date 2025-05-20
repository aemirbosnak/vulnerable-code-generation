//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct {
    int rows;
    int cols;
    float data[MAXSIZE][MAXSIZE];
} Matrix;

void initializeMatrix(Matrix *m);
void displayMatrix(const Matrix *m);
Matrix addMatrices(const Matrix *m1, const Matrix *m2);
Matrix multiplyMatrices(const Matrix *m1, const Matrix *m2);
void romanticMatrix();
void farewell();

int main() {
    romanticMatrix();
    return 0;
}

void romanticMatrix() {
    Matrix matrix1, matrix2, sum, product;

    printf("Ah, my beloved! Let us create our first matrix together. \n");
    printf("Enter the number of rows for your matrix: ");
    scanf("%d", &matrix1.rows);
    
    printf("Enter the number of columns for your matrix: ");
    scanf("%d", &matrix1.cols);

    printf("Let us fill this matrix with our dreams, my love.\n");
    initializeMatrix(&matrix1);
    printf("Our first matrix of love:\n");
    displayMatrix(&matrix1);

    printf("Now, dearest, let us create a second matrix, entwined in beauty.\n");
    printf("Enter the number of rows for your second matrix: ");
    scanf("%d", &matrix2.rows);
    
    printf("Enter the number of columns for your second matrix: ");
    scanf("%d", &matrix2.cols);

    if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) {
        printf("Oh no, my sweet! The two matrices must have the same dimensions to add.\n");
        return;
    }

    printf("Let us fill our second matrix with tender memories.\n");
    initializeMatrix(&matrix2);
    printf("Our second matrix of hearts:\n");
    displayMatrix(&matrix2);

    printf("Now, let us add our matrices, a beautiful union of numbers!\n");
    sum = addMatrices(&matrix1, &matrix2);
    printf("The sum of our matrices, a symbol of our togetherness:\n");
    displayMatrix(&sum);

    if (matrix1.cols != matrix2.rows) {
        printf("Oh, how unfortunate! These matrices cannot be multiplied, my love.\n");
        return;
    }

    printf("Let us create a new masterpiece by multiplying our two matrices:\n");
    product = multiplyMatrices(&matrix1, &matrix2);
    printf("The product of our passion:\n");
    displayMatrix(&product);

    farewell();
}

void initializeMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &m->data[i][j]);
        }
    }
}

void displayMatrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix addMatrices(const Matrix *m1, const Matrix *m2) {
    Matrix result;
    result.rows = m1->rows;
    result.cols = m1->cols;

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    return result;
}

Matrix multiplyMatrices(const Matrix *m1, const Matrix *m2) {
    Matrix result;
    result.rows = m1->rows;
    result.cols = m2->cols;

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

void farewell() {
    printf("Farewell, my love. Until our next mathematical rendezvous!\n");
}