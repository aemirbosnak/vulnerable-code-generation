//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_VAL 1000

// Function to create a bucket
void createBucket(int bucket[], int size) {
    for (int i = 0; i < size; i++) {
        bucket[i] = -1;
    }
}

// Function to insert element into bucket
void insertElement(int bucket[], int size, int element) {
    int i = 0;
    while (bucket[i]!= -1 && element > bucket[i]) {
        i++;
    }
    bucket[i] = element;
}

// Function to sort the array using bucket sort
void bucketSort(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));
    createBucket(bucket, range);
    for (int i = 0; i < size; i++) {
        insertElement(bucket, range, arr[i]);
    }
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i]!= -1) {
            arr[j++] = bucket[i];
            bucket[i] = -1;
        }
    }
}

// Function to print the sorted array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = { 12, 34, 3, 56, 34, 1, 89, 56, 23, 45, 67, 23, 45, 67, 89, 1, 23, 45, 67 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    printArray(arr, size);
    bucketSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}