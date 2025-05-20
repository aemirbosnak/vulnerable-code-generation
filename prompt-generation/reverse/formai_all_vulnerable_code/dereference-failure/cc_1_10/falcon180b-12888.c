//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_multiplication(int **A, int **B, int **C, int n) {
    int i, j, k;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            C[i][j] = 0;
            for(k=0; k<n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print_matrix(int **mat, int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    int **A = (int **)malloc(n * sizeof(int *));
    for(i=0; i<n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
    }

    int **B = (int **)malloc(n * sizeof(int *));
    for(i=0; i<n; i++) {
        B[i] = (int *)malloc(n * sizeof(int));
    }

    int **C = (int **)malloc(n * sizeof(int *));
    for(i=0; i<n; i++) {
        C[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter elements of matrix A:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    clock_t start_time, end_time;
    start_time = clock();
    matrix_multiplication(A, B, C, n);
    end_time = clock();

    printf("Result of matrix multiplication:\n");
    print_matrix(C, n);

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTime taken for matrix multiplication: %lf seconds\n", time_taken);

    return 0;
}