//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000
#define MAX_BUCKETS 1000000

void bucket_sort(int arr[], int n, int range) {
    int *buckets = malloc(MAX_BUCKETS * sizeof(int));
    int bucket_size = MAX_RANGE / range;
    int i, j, k;

    for (i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++) {
        k = arr[i] / range;
        buckets[k]++;
    }

    for (i = 1; i < MAX_BUCKETS; i++) {
        buckets[i] += buckets[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        k = arr[i] / range;
        buckets[k]--;
        arr[--buckets[k]] = arr[i];
    }
}

int main() {
    int n, i, range;
    int arr[MAX_SIZE];
    struct timespec start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the range: ");
    scanf("%d", &range);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    bucket_sort(arr, n, range);
    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    double elapsed_time = (double)(end.tv_sec - start.tv_sec) +
        (double)(end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("\n\nTime taken: %lf seconds\n", elapsed_time);

    return 0;
}