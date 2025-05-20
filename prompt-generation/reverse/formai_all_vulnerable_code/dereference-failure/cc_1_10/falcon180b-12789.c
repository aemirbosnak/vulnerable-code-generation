//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 1000
#define PI 3.14159265358979323846

int main() {
    int i, j, n, max, min, range, bucket_size;
    float *arr, *bucket;
    clock_t start, end;
    float cpu_time_used;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (float *) malloc(n * sizeof(float));
    bucket = (float *) malloc(n * sizeof(float));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min;
    bucket_size = range / n;

    start = clock();

    for (i = 0; i < n; i++) {
        j = (int) ((arr[i] - min) / bucket_size);
        bucket[j] = bucket[j] + 1;
    }

    for (i = 0; i < n; i++) {
        j = (int) ((arr[i] - min) / bucket_size);
        for (int k = 0; k < bucket[j]; k++) {
            printf("%f ", arr[i]);
        }
    }

    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;

    printf("\n\nBucket Sort Completed in %f seconds.\n", cpu_time_used);

    return 0;
}