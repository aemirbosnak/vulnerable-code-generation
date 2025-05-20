//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

void bucketSort(int arr[], int size) {
    int *buckets = (int *) malloc(MAX_VALUE * sizeof(int));
    int bucketSize = MAX_VALUE / size;

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex]++;
    }

    int index = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        if (buckets[i] > 0) {
            for (int j = 0; j < buckets[i]; j++) {
                arr[index++] = i * bucketSize + j * bucketSize;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    generateRandomArray(arr, size);

    bucketSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}