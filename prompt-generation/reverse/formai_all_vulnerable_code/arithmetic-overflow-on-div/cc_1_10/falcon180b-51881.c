//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000 // Maximum number of elements in the array
#define MAX_VALUE 1000 // Maximum value of elements in the array

void createArray(int arr[], int size);
void printArray(int arr[], int size);
void bucketSort(int arr[], int size);
void shellSort(int arr[], int size);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    createArray(arr, size);

    printf("Unsorted array:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("\nSorted array using Bucket Sort:\n");
    printArray(arr, size);

    shellSort(arr, size);

    printf("\nSorted array using Shell Sort:\n");
    printArray(arr, size);

    return 0;
}

void createArray(int arr[], int size) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = max / size;
    int *buckets[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int index = arr[i] / bucketSize;
        int j = 0;
        while (j < size && buckets[index][j]!= 0) {
            j++;
        }
        buckets[index][j] = arr[i];
    }

    int j = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        while (j < size && buckets[i][j]!= 0) {
            arr[j++] = buckets[i][j];
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        free(buckets[i]);
    }
}

void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}