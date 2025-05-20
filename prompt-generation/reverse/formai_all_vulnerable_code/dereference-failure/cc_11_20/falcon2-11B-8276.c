//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Random Matrix Operations
int main() {
    srand(time(NULL)); // Initialize random seed

    int m = rand() % 10;
    int n = rand() % 10;
    int k = rand() % 10;

    int **A = (int **)malloc(m * sizeof(int *)); // Allocate memory for A
    for (int i = 0; i < m; i++) {
        A[i] = (int *)malloc(n * sizeof(int)); // Allocate memory for each row of A
    }

    // Initialize A
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100; // Fill A with random integers
        }
    }

    int **B = (int **)malloc(m * sizeof(int *)); // Allocate memory for B
    for (int i = 0; i < m; i++) {
        B[i] = (int *)malloc(n * sizeof(int)); // Allocate memory for each row of B
    }

    // Initialize B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = rand() % 100; // Fill B with random integers
        }
    }

    int **C = (int **)malloc(k * sizeof(int *)); // Allocate memory for C
    for (int i = 0; i < k; i++) {
        C[i] = (int *)malloc(n * sizeof(int)); // Allocate memory for each row of C
    }

    // Perform Matrix Operations
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j]; // Add A and B element-wise
        }
    }

    // Print the result
    printf("Matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix C:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < m; i++) {
        free(A[i]); // Free memory for each row of A
    }
    free(A); // Free memory for A

    for (int i = 0; i < m; i++) {
        free(B[i]); // Free memory for each row of B
    }
    free(B); // Free memory for B

    for (int i = 0; i < k; i++) {
        free(C[i]); // Free memory for each row of C
    }
    free(C); // Free memory for C

    return 0;
}