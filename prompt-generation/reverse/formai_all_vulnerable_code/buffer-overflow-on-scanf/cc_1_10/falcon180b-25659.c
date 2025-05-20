//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE 100

void generateArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void bucketSort(int arr[], int size) {
    int *buckets[RANGE];
    for (int i = 0; i < RANGE; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * size);
    }

    for (int i = 0; i < size; i++) {
        int index = arr[i] / RANGE;
        int *bucket = buckets[index];
        bucket[i] = arr[i];
    }

    for (int i = 0; i < RANGE; i++) {
        qsort(buckets[i], size, sizeof(int), compare);
    }

    int index = 0;
    for (int i = 0; i < RANGE; i++) {
        for (int j = 0; j < size; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < RANGE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array (<= %d): ", MAX_SIZE);
    scanf("%d", &size);

    int arr[size];
    generateArray(arr, size);
    printArray(arr, size);

    bucketSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}