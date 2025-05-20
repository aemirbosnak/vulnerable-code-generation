//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000 // Maximum size of input array

// Function to perform matrix multiplication
void matrix_multiply(int **A, int **B, int **C, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(int argc, char **argv) {
    int n, i, j;
    int **A, **B, **C;
    FILE *fp;

    // Read input from file
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &n);
    A = (int **) malloc(n * sizeof(int *));
    B = (int **) malloc(n * sizeof(int *));
    C = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        A[i] = (int *) malloc(n * sizeof(int));
        B[i] = (int *) malloc(n * sizeof(int));
        C[i] = (int *) malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(fp, "%d", &A[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(fp, "%d", &B[i][j]);
        }
    }
    fclose(fp);

    // Perform matrix multiplication
    matrix_multiply(A, B, C, n);

    // Write output to file
    fp = fopen("output.txt", "w");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fprintf(fp, "%d ", C[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}