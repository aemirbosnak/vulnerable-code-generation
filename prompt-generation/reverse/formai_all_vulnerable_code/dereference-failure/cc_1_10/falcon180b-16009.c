//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

/* Function to swap two elements */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to create an array of given size */
int* createArray(int size) {
    int* arr = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

/* Function to sort the array using bucket sort */
void bucketSort(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketSize = max / size;
    int* buckets = (int*) malloc(bucketSize * sizeof(int));
    for (int i = 0; i < size; i++) {
        int index = arr[i] / bucketSize;
        buckets[index]++;
    }
    int index = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * bucketSize + j;
        }
    }
}

/* Function to print an array */
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 10;
    int* arr = createArray(size);
    printf("Unsorted array:\n");
    printArray(arr, size);
    bucketSort(arr, size);
    printf("Sorted array:\n");
    printArray(arr, size);
    free(arr);
    return 0;
}