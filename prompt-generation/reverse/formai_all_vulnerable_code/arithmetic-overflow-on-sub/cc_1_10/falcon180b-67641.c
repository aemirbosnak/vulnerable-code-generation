//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n, m, i, j, k, l, count = 0;
    double a[100][100], b[100][100], c[100][100], sum;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &n, &m);

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &n, &m);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            c[i][j] = 0;
            for (k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nProduct of entered matrices:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%0.2lf ", c[i][j]);
        }
        printf("\n");
    }

    printf("\nCPU time used: %0.6lf seconds\n", cpu_time_used);

    return 0;
}