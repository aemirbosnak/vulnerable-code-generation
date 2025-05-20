//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];
    int i, j, k;

    // Taking input for matrix 1
    printf("Enter elements of matrix 1:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Taking input for matrix 2
    printf("Enter elements of matrix 2:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Performing addition of two matrices
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Displaying result of addition
    printf("Result of addition:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Performing multiplication of two matrices
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            result[i][j] = 0;
            for(k=0; k<COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Displaying result of multiplication
    printf("Result of multiplication:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Transposing matrix 1
    printf("Transpose of matrix 1:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d ", matrix1[j][i]);
        }
        printf("\n");
    }

    return 0;
}