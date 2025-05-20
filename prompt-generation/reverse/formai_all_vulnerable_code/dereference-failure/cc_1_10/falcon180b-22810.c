//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100000
#define RANGE 1000000

void bucket_sort(int arr[], int n);

int main() {
    int n, i;
    int *arr;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    bucket_sort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bucket Sort completed in %f seconds.\n", cpu_time_used);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucket_sort(int arr[], int n) {
    int i, j, min, max, range, bucket_size, *bucket;

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

    range = max - min + 1;
    bucket_size = RANGE / range;

    bucket = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range;
        bucket[j]++;
    }

    for (i = 1; i < bucket_size; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = (arr[i] - min) / range;
        bucket[j]--;
        arr[bucket[j]] = arr[i];
    }

    free(bucket);
}