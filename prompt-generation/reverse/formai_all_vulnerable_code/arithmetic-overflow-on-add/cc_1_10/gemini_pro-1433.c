//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Create a bucket of size n
int* createBucket(int n) {
    int* bucket = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    return bucket;
}

// Insert an element into a bucket
void insertIntoBucket(int* bucket, int element) {
    bucket[element]++;
}

// Sort the elements in a bucket
void sortBucket(int* bucket, int n) {
    for (int i = 0; i < n; i++) {
        while (bucket[i] > 0) {
            printf("%d ", i);
            bucket[i]--;
        }
    }
}

// Bucket sort implementation
void bucketSort(int* arr, int n) {
    // Create a bucket for each element in the array
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    int* bucket = createBucket(maxElement + 1);

    // Insert each element into a bucket
    for (int i = 0; i < n; i++) {
        insertIntoBucket(bucket, arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i <= maxElement; i++) {
        sortBucket(bucket, i);
    }

    // Free the bucket
    free(bucket);
}

// Print an array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the array from the user
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("The sorted array is: ");
    printArray(arr, n);

    // Free the array
    free(arr);

    return 0;
}