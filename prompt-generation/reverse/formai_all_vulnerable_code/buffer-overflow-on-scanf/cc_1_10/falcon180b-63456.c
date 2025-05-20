//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n, i, j, count;
    double a, b, c, d, e, f, g, h, x, y, z;
    double *p, *q, *r;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    p = (double *)malloc(n * n * sizeof(double));
    q = (double *)malloc(n * n * sizeof(double));
    r = (double *)malloc(n * n * sizeof(double));

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &p[i * n + j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &q[i * n + j]);
        }
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (count = 0; count < n; count++) {
                r[i * n + j] += p[i * n + count] * q[count * n + j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The product of the matrices is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", r[i * n + j]);
        }
        printf("\n");
    }

    printf("The time taken to compute the product is %lf seconds.\n", cpu_time_used);

    free(p);
    free(q);
    free(r);

    return 0;
}