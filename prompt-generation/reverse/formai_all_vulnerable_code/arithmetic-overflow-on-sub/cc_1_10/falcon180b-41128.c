//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n, i, j, k, m, count = 0;
    float a[100][100], b[100][100], c[100][100], sum = 0.0;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &n, &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element a(%d,%d): ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element b(%d,%d): ", i, j);
            scanf("%f", &b[i][j]);
        }
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

    printf("\nThe product of matrices A and B is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.2f\t", c[i][j]);
        }
        printf("\n");
    }

    printf("\nThe total number of multiplications is: %d\n", count);
    printf("The total time taken is: %lf seconds\n", cpu_time_used);

    return 0;
}