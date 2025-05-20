//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5
#define N 7

int main() {
    int i, j, k;
    char matrix[M][N];
    char result[M][N];

    // Initialize matrices
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            matrix[i][j] = i * j % 10;
            result[i][j] = 0;
        }
    }

    // Matrix addition
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }

    // Matrix multiplication
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            int sum = 0;
            for (k = 0; k < N; k++) {
                sum += matrix[i][k] * result[k][j];
            }
            result[i][j] = sum % 10;
        }
    }

    // Print result
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}