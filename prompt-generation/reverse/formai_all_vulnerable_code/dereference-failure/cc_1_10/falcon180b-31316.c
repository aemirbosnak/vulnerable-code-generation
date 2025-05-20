//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int bucket_sort(int *arr, int size) {
    int i, j, max_val, *bucket;
    max_val = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    bucket = (int *) malloc(max_val * sizeof(int));
    for (i = 0; i < max_val; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < size; i++) {
        bucket[arr[i]]++;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < bucket[arr[i]]; j++) {
            arr[i * MAX_SIZE + j] = arr[i];
        }
    }
    free(bucket);
    return 0;
}

int main() {
    int arr[MAX_SIZE], size, i;
    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
    printf("Before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, size);
    printf("After sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}