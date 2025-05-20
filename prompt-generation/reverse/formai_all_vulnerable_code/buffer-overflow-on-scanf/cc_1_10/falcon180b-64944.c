//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bucketSort(int arr[], int size) {
    int bucketSize = 10;
    int* buckets[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = (int*)malloc(bucketSize * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int indexInBucket = 0;

        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = (int*)malloc(bucketSize * sizeof(int));
        }

        while (indexInBucket < bucketSize && buckets[bucketIndex][indexInBucket] == -1) {
            indexInBucket++;
        }

        if (indexInBucket == bucketSize) {
            printf("Bucket Overflow\n");
            exit(0);
        }

        buckets[bucketIndex][indexInBucket] = arr[i];
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        quickSort(buckets[i], 0, bucketSize - 1);
    }

    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        swap(&arr[i], &arr[j]);
    }

    bucketSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}