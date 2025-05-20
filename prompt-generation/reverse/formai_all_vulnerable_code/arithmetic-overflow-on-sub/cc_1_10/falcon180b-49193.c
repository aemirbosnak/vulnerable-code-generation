//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100
#define PI 3.14159265358979323846

int main()
{
    int i, j, n;
    double x, y, z, sum;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    double **a = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
    {
        a[i] = (double *)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100;
        }
    }

    start = clock();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += a[i][k] * a[k][j];
            }
            a[i][j] = sum;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %lf seconds\n", cpu_time_used);

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}