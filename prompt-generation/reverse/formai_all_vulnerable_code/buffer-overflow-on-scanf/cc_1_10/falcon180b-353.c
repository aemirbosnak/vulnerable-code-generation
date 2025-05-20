//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 // maximum number of elements in the array

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomNumber(1, 100);
    }

    printf("Unsorted array: ");
    printArray(arr, size);

    int bucketSize = size / 10;
    int *buckets[MAX_SIZE];

    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = malloc(sizeof(int) * MAX_SIZE);
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int indexInBucket = 0;
        while (buckets[bucketIndex][indexInBucket]!= 0) {
            indexInBucket++;
        }
        buckets[bucketIndex][indexInBucket] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int indexInBucket = 0;
        while (buckets[bucketIndex][indexInBucket]!= arr[i]) {
            indexInBucket++;
        }
        buckets[bucketIndex][indexInBucket] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int indexInBucket = 0;
        while (buckets[bucketIndex][indexInBucket]!= 0) {
            indexInBucket++;
        }
        arr[i] = buckets[bucketIndex][indexInBucket];
    }

    printf("Sorted array: ");
    printArray(arr, size);

    for (int i = 0; i < bucketSize; i++) {
        free(buckets[i]);
    }

    return 0;
}