//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MIN_VALUE 1
#define MAX_VALUE 1000

// Function to generate random numbers between min and max values
void generateRandomNumbers(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
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
    int buckets[MAX_SIZE] = {0};
    int max = arr[0];
    int min = arr[0];

    // Find the minimum and maximum values in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and bucket size
    int range = max - min + 1;
    int bucketSize = range / MAX_SIZE;

    // Place the elements in the appropriate buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        buckets[bucketIndex]++;
    }

    // Concatenate the buckets to get the sorted array
    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * bucketSize + min;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generateRandomNumbers(arr, size);
    printf("Unsorted array:\n");
    printArray(arr, size);

    bucketSort(arr, size);
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}