//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int bucketCount = MAX_VALUE / (MAX_SIZE / size);
    int *buckets[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = calloc(size, sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / (MAX_SIZE / bucketCount);
        buckets[bucketIndex][i % bucketIndex] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < size; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int randIndex = rand() % size;
        swap(&arr[i], &arr[randIndex]);
    }

    printf("Randomized array: ");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}