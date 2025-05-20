//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int n, i, j, k, m;
    double a[100][100], b[100][100], c[100][100], sum = 0;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d%d", &n, &m);

    printf("Enter the elements of the first matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    start = clock();

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            for(k=0; k<m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The product of the matrices is:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%lf\t", c[i][j]);
        }
        printf("\n");
    }

    printf("CPU time used: %lf seconds\n", cpu_time_used);

    return 0;
}