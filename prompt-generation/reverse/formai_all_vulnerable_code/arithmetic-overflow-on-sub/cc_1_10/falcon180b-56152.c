//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void bucketSort(int arr[], int n) {
    int i, j, max, min, range, *bucket;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the maximum value of the array: ");
    scanf("%d", &max);

    printf("Enter the minimum value of the array: ");
    scanf("%d", &min);

    range = max - min + 1;
    bucket = (int *)malloc(range * sizeof(int));

    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 1; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }

    start = clock();
    for (i = n - 1; i >= 0; i--) {
        j = arr[i] - min;
        bucket[j]--;
        arr[bucket[j]] = arr[i];
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bucket sort completed in %lf seconds\n", cpu_time_used);
}

int main() {
    int n, i, max, min, *arr;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the maximum value of the array: ");
    scanf("%d", &max);

    printf("Enter the minimum value of the array: ");
    scanf("%d", &min);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}