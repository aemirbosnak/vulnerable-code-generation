//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14159265358979323846

float *multiplyMatrices(float *matrix1, float *matrix2, int row, int col, int other);

int main() {
    int rows, cols;

    printf("Enter number of rows:\n");
    scanf("%d", &rows);
    printf("Enter number of columns:\n");
    scanf("%d", &cols);

    float *matrix1 = (float*) malloc(rows * cols * sizeof(float));
    float *matrix2 = (float*) malloc(rows * cols * sizeof(float));
    float *result = (float*) malloc(rows * cols * sizeof(float));
    float *temp = (float*) malloc(rows * cols * sizeof(float));

    printf("\nEnter first matrix:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("Enter matrix element [%d][%d]: ", i, j);
            scanf("%f", &matrix1[i * cols + j]);
        }
    }

    printf("\nEnter second matrix:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("Enter matrix element [%d][%d]: ", i, j);
            scanf("%f", &matrix2[i * cols + j]);
        }
    }

    result = multiplyMatrices(matrix1, matrix2, rows, cols, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i * cols + j] = result[i * cols + j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i * cols + j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i * cols + j] += temp[i * cols + k] * matrix2[k * cols + j];
            }
        }
    }

    printf("\nResult:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%f ", result[i * cols + j]);
        }
        printf("\n");
    }

    free(matrix1);
    free(matrix2);
    free(result);
    free(temp);

    return 0;
}

float *multiplyMatrices(float *matrix1, float *matrix2, int row, int col, int other) {
    float *result = (float*) malloc(row * other * sizeof(float));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < other; j++) {
            result[i * other + j] = 0;
            for (int k = 0; k < col; k++) {
                result[i * other + j] += matrix1[i * col + k] * matrix2[k * other + j];
            }
        }
    }

    return result;
}