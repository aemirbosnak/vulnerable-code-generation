//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows1, cols1, rows2, cols2, i, j, k;
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d%d", &rows1, &cols1);

    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d%d", &rows2, &cols2);

    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    if (rows1!= rows2 || cols1!= cols2) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Product of matrices:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}