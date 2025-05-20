//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void bucket_sort(int arr[], int n) {
    int i, j, count[MAX_SIZE] = { 0 };
    int *output = malloc(n * sizeof(int));

    if (!output) {
        printf("Memory error\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        count[(arr[i] / 10) % 100]++;
    }

    for (i = 1; i < 100; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = (arr[i] / 10) % 100;
        output[count[j] - 1] = arr[i];
        count[j]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

int main() {
    int i, n, max, min;
    int arr[MAX_SIZE];
    struct timespec start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
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

    clock_gettime(CLOCK_REALTIME, &start);
    bucket_sort(arr, n);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    return 0;
}