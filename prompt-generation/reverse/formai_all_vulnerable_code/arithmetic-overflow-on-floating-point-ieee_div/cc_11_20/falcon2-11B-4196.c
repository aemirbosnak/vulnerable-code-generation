//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a 3x3 matrix
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Print the matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    int transposed[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    // Calculate the determinant of the matrix
    int determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
                        matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
                        matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    printf("\nDeterminant of the Matrix:\n");
    printf("%d\n", determinant);

    // Calculate the inverse of the matrix
    int inverse[3][3];
    double det = (double) determinant;
    det = 1 / det;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inverse[i][j] = det * (matrix[j][i] * transposed[i][j]);
        }
    }

    // Print the inverse matrix
    printf("\nInverse Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", inverse[i][j]);
        }
        printf("\n");
    }

    return 0;
}