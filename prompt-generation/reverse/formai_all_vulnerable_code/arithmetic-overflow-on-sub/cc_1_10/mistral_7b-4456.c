//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void bucketSort(int arr[], int n) {
    int i, j, bucket, *count, *output;
    int buckets[10] = {0};

    count = (int*)calloc(11, sizeof(int));

    for (i = 0; i < n; i++) {
        count[arr[i] + 1]++;
    }

    for (i = 0; i < 10; i++) {
        while (count[i]--) {
            bucket = i;
            output[j++] = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

void printArray(int arr[], int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        if (i != 0)
            printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main() {
    int arr[SIZE] = {3, 6, 8, 5, 7, 2, 9, 1, 4, 10};

    printf("Unsorted array: \n");
    printArray(arr, SIZE);

    bucketSort(arr, SIZE);

    printf("Sorted array: \n");
    printArray(arr, SIZE);

    return 0;
}