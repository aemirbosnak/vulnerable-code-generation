//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Matrix operations
void matrixMultiply(float *A, float *B, float *C, int m, int n) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i * n + j] += A[i * m + k] * B[k * n + j];
            }
        }
    }
}

void matrixAddition(float *A, float *B, float *C, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            C[i * n + j] = A[i * m + j] + B[i * m + j];
        }
    }
}

void matrixTranspose(float *A, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            float temp = A[i * n + j];
            A[i * n + j] = A[j * m + i];
            A[j * m + i] = temp;
        }
    }
}

int main() {
    float A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    float B[3][4] = {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}};
    float C[3][4];

    // Matrix multiplication
    matrixMultiply(A, B, C, 3, 4);

    // Matrix addition
    matrixAddition(A, B, C, 3, 4);

    // Matrix transpose
    matrixTranspose(A, 3, 4);

    // Print the result
    printf("C = \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.2f ", C[i * 4 + j]);
        }
        printf("\n");
    }

    return 0;
}