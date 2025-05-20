//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bucket_sort(int *arr, int n) {
    int i, j, range, bucket_size;
    int *bucket;

    range = arr[0] - arr[n-1];
    bucket_size = range / n;
    bucket = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] / bucket_size]++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[j * n + i] = i * bucket_size + j * bucket_size;
        }
    }

    free(bucket);
    return 0;
}

int main() {
    int n, i;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(0));
    for (i = 0; i < n; i++) {
        int temp = arr[i];
        int j = rand() % n;
        arr[i] = arr[j];
        arr[j] = temp;
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}