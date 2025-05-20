//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n, m, i, j, k, l, sum = 0;
    double a[100][100], b[100][100], c[100][100], temp[100][100];
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Enter element %d%d: ", i+1, j+1);
            scanf("%lf", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[i][j] = rand() % 10;
        }
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                for (l = 0; l < m; l++) {
                    temp[i][j] += a[i][k] * b[k][l] * c[l][j];
                }
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The product of the matrices is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%lf ", temp[i][j]);
        }
        printf("\n");
    }

    printf("The CPU time used is %lf seconds.\n", cpu_time_used);

    return 0;
}