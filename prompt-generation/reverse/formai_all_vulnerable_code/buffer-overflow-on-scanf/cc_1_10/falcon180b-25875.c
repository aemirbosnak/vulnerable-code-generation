//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n, i, j, k;
    int a[100][100], b[100][100], c[100][100];
    int **result;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the matrices (max 100): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    result = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Multiplication completed in %lf seconds\n", cpu_time_used);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}