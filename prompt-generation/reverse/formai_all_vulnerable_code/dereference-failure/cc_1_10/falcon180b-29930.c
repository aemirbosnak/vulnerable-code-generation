//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int max = arr[0], min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int* bucket = (int*)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int index = arr[i] - min;
        bucket[index]++;
    }
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i + min;
            bucket[i]--;
        }
    }
    free(bucket);
}

int main() {
    srand(time(0));
    int arr[MAX_SIZE];
    int size = rand() % MAX_SIZE + 1;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    printf("Before sorting:\n");
    printArray(arr, size);
    bucketSort(arr, size);
    printf("After sorting:\n");
    printArray(arr, size);
    return 0;
}