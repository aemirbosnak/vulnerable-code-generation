//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main() {
    int i, j, n, m, count = 0;
    int *a, *b;
    int sum = 0;
    clock_t start, end;
    double cpu_time_used;
    FILE *fp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("Enter the number of elements to be added: ");
    scanf("%d", &m);

    b = (int *) malloc(m * sizeof(int));

    printf("Enter %d elements:\n", m);
    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    start = clock();

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i] += b[j];
        }
    }

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of the array elements is: %d\n", sum);
    printf("The CPU time used is: %lf seconds\n", cpu_time_used);

    free(a);
    free(b);

    return 0;
}