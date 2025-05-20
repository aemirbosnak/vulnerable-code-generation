//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int m[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int addMatrix(int a[3][3], int b[3][3], int c[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return 0;
}

// Function to multiply two matrices
int multiplyMatrix(int a[3][3], int b[3][3], int c[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return 0;
}

int main() {
    // Declare two 3x3 matrices
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Declare a 3x3 matrix to store the result of matrix addition
    int c[3][3];

    // Add two matrices
    addMatrix(a, b, c);

    // Print the result
    printMatrix(c, 3);

    // Declare two 3x3 matrices
    int d[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int e[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Declare a 3x3 matrix to store the result of matrix multiplication
    int f[3][3];

    // Multiply two matrices
    multiplyMatrix(d, e, f);

    // Print the result
    printMatrix(f, 3);

    return 0;
}