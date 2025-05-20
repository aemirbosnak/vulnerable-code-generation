//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, columns, matrix[5][5], i, j, k, m, n;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    printf("Enter the elements of the matrix: \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transpose the matrix
    for (m = 0; m < rows; m++) {
        for (n = 0; n < columns; n++) {
            matrix[m][n] = matrix[n][m];
        }
    }

    // Print the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Multiply the matrix with a scalar
    printf("\nMultiplied Matrix with Scalar 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            matrix[i][j] *= 2;
        }
    }

    // Print the multiplied matrix
    printf("\nMultiplied Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate the sum of the elements in the matrix
    int sum = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            sum += matrix[i][j];
        }
    }
    printf("\nSum of the elements in the matrix: %d\n", sum);

    return 0;
}