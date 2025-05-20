//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

void multiply(int A[][COLS], int B[][ROWS], int C[][COLS]);
void printMatrix(int matrix[][COLS], int rows, int cols);

int main() {
    int A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    multiply(A, B, C);
    printf("\nMatrix A:\n");
    printMatrix(A, ROWS, COLS);
    printf("\nMatrix B:\n");
    printMatrix(B, ROWS, COLS);
    printf("\nResultant Matrix C:\n");
    printMatrix(C, ROWS, COLS);

    return 0;
}

void multiply(int A[][COLS], int B[][ROWS], int C[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            C[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}