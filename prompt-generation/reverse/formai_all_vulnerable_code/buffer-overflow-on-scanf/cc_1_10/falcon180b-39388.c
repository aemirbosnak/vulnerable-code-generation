//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

int generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    return 0;
}

void bucketSort(int arr[], int size) {
    int *bucket = (int *)malloc(MAX_VALUE * sizeof(int));
    int *count = (int *)malloc(MAX_VALUE * sizeof(int));
    int maxValue = arr[0];
    int minValue = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    int range = maxValue - minValue + 1;
    int bucketSize = range / size;
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int bucketIndex = (arr[i] - minValue) / bucketSize;
        bucket[bucketIndex] = arr[i];
        count[bucketIndex]++;
    }
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i];
        }
    }
    free(bucket);
    free(count);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    generateRandomArray(arr, size);
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, size);
    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}