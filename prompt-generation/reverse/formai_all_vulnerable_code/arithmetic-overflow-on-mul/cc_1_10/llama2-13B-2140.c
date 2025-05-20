//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to perform matrix multiplication
void multiply_matrices(int **a, int **b, int **c) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                int sum = 0;
                for (int p = 0; p < 3; p++) {
                    sum += a[i][p] * b[p][j];
                }
                c[i][j] = sum;
            }
        }
    }
}

// Function to perform matrix addition
void add_matrices(int **a, int **b, int **c) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                c[i][j] += a[i][k] + b[k][j];
            }
        }
    }
}

int main() {
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int c[3][3];

    // Perform matrix multiplication
    multiply_matrices(a, b, c);

    // Print the result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    add_matrices(a, b, c);

    // Print the result
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}