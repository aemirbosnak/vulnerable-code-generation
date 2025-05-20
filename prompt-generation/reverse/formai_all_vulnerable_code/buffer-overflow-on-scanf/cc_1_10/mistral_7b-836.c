//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define ROWS1 3
#define COLS1 3
#define ROWS2 3
#define COLS2 3

void multiplyMatrices(float result[][COLS2], float mat1[][ROWS1], float mat2[][ROWS2], int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    float mat1[ROWS1][COLS1], mat2[ROWS2][COLS2], result[ROWS1][COLS2];
    int i, j, k;

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < ROWS1; i++) {
        for (j = 0; j < COLS1; j++) {
            scanf("%f", &mat1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < ROWS2; i++) {
        for (j = 0; j < COLS2; j++) {
            scanf("%f", &mat2[i][j]);
        }
    }

    multiplyMatrices(result, mat1, mat2, ROWS1, COLS1, ROWS2, COLS2);

    printf("Product of the entered matrices:\n");
    for (i = 0; i < ROWS1; i++) {
        for (j = 0; j < COLS2; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}