//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to multiply two matrices
void multiplyMatrices(int m1[3][3], int m2[3][3], int m3[3][3]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int m[3][3], int mT[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mT[j][i] = m[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int m[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int m3[3][3];
    int mT[3][3];

    // Multiply two matrices
    multiplyMatrices(m1, m2, m3);

    // Transpose a matrix
    transposeMatrix(m3, mT);

    // Print the results
    printf("Original Matrix:\n");
    printMatrix(m1);
    printf("Transposed Matrix:\n");
    printMatrix(mT);

    return 0;
}