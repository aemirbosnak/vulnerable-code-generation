//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000
#define PI 3.14159265358979323846

int main() {
    int n, m, i, j, k, l;
    int a[MAX], b[MAX], c[MAX], d[MAX];
    double suma, sumb, sumc, sumd;
    double sum, avg;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000;
        b[i] = rand() % 1000;
    }

    start = clock();

    for (i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
        d[i] = a[i] - b[i];
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken by the CPU: %lf seconds\n", cpu_time_used);

    for (i = 0; i < n; i++) {
        suma += a[i];
        sumb += b[i];
        sumc += c[i];
        sumd += d[i];
    }

    avg = (double) n / ((double) n + 1);

    printf("\nSum of array a: %lf\n", suma);
    printf("Sum of array b: %lf\n", sumb);
    printf("Sum of array c: %lf\n", sumc);
    printf("Sum of array d: %lf\n", sumd);

    return 0;
}