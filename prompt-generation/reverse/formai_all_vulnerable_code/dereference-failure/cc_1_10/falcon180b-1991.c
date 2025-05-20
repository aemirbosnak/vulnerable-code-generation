//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to create an array of random integers
void createArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = max / size;
    int *buckets[MAX_SIZE];

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = malloc(sizeof(int) * size);
        }
        int *bucket = buckets[bucketIndex];
        int j = 0;
        while (j < i && arr[j] / bucketSize == bucketIndex) {
            swap(&arr[j], &arr[i]);
            j++;
        }
        bucket[j] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (buckets[i]!= NULL) {
            for (int j = 0; j < i; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    createArray(arr, size);
    printf("Unsorted array:\n");
    printArray(arr, size);

    bucketSort(arr, size);
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}