//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main() {
    int i, j, n, sum = 0;
    double x, y, z;
    double **a, **b, **c;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of rows and columns for the matrices:\n");
    scanf("%d %d", &n, &n);

    a = (double **)malloc(n * sizeof(double *));
    b = (double **)malloc(n * sizeof(double *));
    c = (double **)malloc(n * sizeof(double *));

    for(i=0; i<n; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
        b[i] = (double *)malloc(n * sizeof(double));
        c[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the elements of matrix A:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    start = clock();
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            c[i][j] = 0;
            for(int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The product of matrices A and B is:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }

    printf("The time taken to multiply the matrices is %lf seconds.\n", cpu_time_used);

    for(i=0; i<n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}