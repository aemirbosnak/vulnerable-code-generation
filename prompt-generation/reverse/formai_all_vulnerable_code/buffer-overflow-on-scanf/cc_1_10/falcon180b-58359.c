//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n, k;
    double *array;
    int *count;
    int **bucket;
    int i, j, index;
    double range;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    array = (double*) malloc(n * sizeof(double));
    count = (int*) malloc(n * sizeof(int));
    bucket = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        bucket[i] = (int*) malloc(n * sizeof(int));
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &array[i]);
    }

    start = clock();
    for (i = 0; i < n; i++) {
        index = (int) (n * array[i]);
        if (index >= n) {
            index = n - 1;
        }
        bucket[index][count[index]] = i;
        count[index]++;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        k = 0;
        while (bucket[i][k]!= -1) {
            printf("%d ", bucket[i][k]);
            k++;
        }
    }

    printf("\nTime taken: %.2lf seconds\n", cpu_time_used);

    return 0;
}