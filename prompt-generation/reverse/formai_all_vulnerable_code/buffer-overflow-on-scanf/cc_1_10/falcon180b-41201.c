//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the index of the minimum element in a bucket
int findMin(int arr[], int size) {
    int minIndex = 0;
    for(int i=1; i<size; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int* buckets[MAX_SIZE];
    int bucketSize = (int)sqrt(size);
    for(int i=0; i<bucketSize; i++) {
        buckets[i] = malloc(sizeof(int)*size);
    }
    for(int i=0; i<size; i++) {
        int bucketIndex = arr[i]/bucketSize;
        int index = findMin(buckets[bucketIndex], size);
        buckets[bucketIndex][index] = arr[i];
    }
    int index = 0;
    for(int i=0; i<bucketSize; i++) {
        for(int j=0; j<size; j++) {
            arr[index++] = buckets[i][j];
        }
    }
    for(int i=0; i<bucketSize; i++) {
        free(buckets[i]);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}