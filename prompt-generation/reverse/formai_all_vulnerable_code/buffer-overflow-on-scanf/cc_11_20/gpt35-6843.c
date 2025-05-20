//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int rowA, colA, rowB, colB;

    printf("Enter the number of rows and columns of Matrix A: ");
    scanf("%d %d", &rowA, &colA);

    int matrixA[rowA][colA];
    int i, j;

    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            printf("Enter the %d %d element of Matrix A: ", i+1, j+1);
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the number of rows and columns of Matrix B: ");
    scanf("%d %d", &rowB, &colB);

    while (colA != rowB) {
        printf("Error: columns of Matrix A must be equal to rows of Matrix B.\n");

        printf("Enter the number of rows and columns of Matrix A: ");
        scanf("%d %d", &rowA, &colA);

        for (i = 0; i < rowA; i++) {
            for (j = 0; j < colA; j++) {
                printf("Enter the %d %d element of Matrix A: ", i+1, j+1);
                scanf("%d", &matrixA[i][j]);
            }
        }

        printf("Enter the number of rows and columns of Matrix B: ");
        scanf("%d %d", &rowB, &colB);
    }

    int matrixB[rowB][colB];

    for (i = 0; i < rowB; i++) {
        for (j = 0; j < colB; j++) {
            printf("Enter the %d %d element of Matrix B: ", i+1, j+1);
            scanf("%d", &matrixB[i][j]);
        }
    }

    int sum[rowA][colB];

    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            sum[i][j] = 0;

            for (int k = 0; k < colA; k++) {
                sum[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("Matrix A: \n");

    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colA; j++) {
            printf("%d ", matrixA[i][j]);
        }

        printf("\n");
    }

    printf("Matrix B: \n");

    for (i = 0; i < rowB; i++) {
        for (j = 0; j < colB; j++) {
            printf("%d ", matrixB[i][j]);
        }

        printf("\n");
    }

    printf("Matrix A * Matrix B: \n");

    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            printf("%d ", sum[i][j]);
        }

        printf("\n");
    }

    return 0;
}