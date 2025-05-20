//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define MAX_RANGE 1000000

void bucket_sort(int *arr, int size) {
    int i, j, n;
    int *bucket[MAX_RANGE];
    int max_val = arr[0];
    int min_val = arr[0];

    for (i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    n = max_val - min_val + 1;

    for (i = 0; i < n; i++) {
        bucket[i] = (int *) malloc(sizeof(int) * size);
    }

    for (i = 0; i < size; i++) {
        j = (arr[i] - min_val) / ((max_val - min_val) / n);
        bucket[j][bucket_index(bucket[j], 0, i - 1)] = arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = bucket[((arr[i] - min_val) / ((max_val - min_val) / n))][i];
    }
}

int bucket_index(int *bucket, int start, int end) {
    int step = (end - start + 1) / (sizeof(int) * 8);
    int mask = (1 << (sizeof(int) * 8 - 1)) - 1;
    int index = start;
    while (index <= end) {
        if (bucket[index >> step] & (1 << (index & mask))) {
            return index;
        }
        index++;
    }
    return -1;
}

int main() {
    int size, i;
    int *arr;
    clock_t start, end;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = (int *) malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }

    start = clock();
    bucket_sort(arr, size);
    end = clock();

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}