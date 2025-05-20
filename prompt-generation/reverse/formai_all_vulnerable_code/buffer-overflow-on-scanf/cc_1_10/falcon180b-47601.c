//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int bucketSize = maxVal / size;
    int numBuckets = maxVal / bucketSize + 1;

    int *buckets[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * size);
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int indexInBucket = 0;
        while (indexInBucket < size && buckets[bucketIndex][indexInBucket]!= -1) {
            indexInBucket++;
        }
        buckets[bucketIndex][indexInBucket] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter array size: ");
    scanf("%d", &size);

    generateRandomArray(arr, size);
    printf("Before sorting:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("After sorting:\n");
    printArray(arr, size);

    return 0;
}