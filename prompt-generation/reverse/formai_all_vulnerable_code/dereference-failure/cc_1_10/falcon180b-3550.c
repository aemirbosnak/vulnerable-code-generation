//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_multiply(int **A, int **B, int **C, int n) {
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

void generate_matrix(int **A, int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            A[i][j] = rand() % 10;
        }
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

    generate_matrix(A, n);
    generate_matrix(B, n);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    matrix_multiply(A, B, C, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU Time used: %lf seconds\n", cpu_time_used);

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<n; i++) {
        free(A[i]);
    }
    free(A);

    for(i=0; i<n; i++) {
        free(B[i]);
    }
    free(B);

    for(i=0; i<n; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}