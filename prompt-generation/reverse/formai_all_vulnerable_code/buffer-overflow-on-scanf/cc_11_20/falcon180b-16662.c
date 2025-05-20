//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_RANGE 1000

int main() {
    int i, j, n, max, min, range, *arr;
    clock_t start, end;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
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

    int *bucket = (int *)malloc(range * sizeof(int));
    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 1; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }

    int *sorted_arr = (int *)malloc(n * sizeof(int));

    for (i = n - 1; i >= 0; i--) {
        sorted_arr[--bucket[arr[i] - min]] = arr[i];
    }

    for (i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }

    end = clock();

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}