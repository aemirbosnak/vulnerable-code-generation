//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int n, i, j, k, m, flag = 0;
    double a[10][10], b[10][10], c[10][10], det;
    char ch;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the order of the matrices: ");
    scanf("%d", &n);

    printf("\nEnter elements of first matrix\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%lf", &a[i][j]);

    printf("\nEnter elements of second matrix\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%lf", &b[i][j]);

    start = clock();

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            c[i][j] = 0;
            for(k=0; k<n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nProduct of entered matrices:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%lf\t", c[i][j]);
        printf("\n");
    }

    printf("\nCPU time used: %lf seconds\n", cpu_time_used);

    return 0;
}