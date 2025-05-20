//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define BUCKET_COUNT 10

// Define a structure for the buckets
struct Bucket {
    int *arr;
    int count;
};

// Function to initialize buckets
void initializeBuckets(struct Bucket buckets[]) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i].arr = malloc(MAX * sizeof(int));
        buckets[i].count = 0;
    }
}

// Function to distribute elements into buckets
void distributeToBuckets(int arr[], int n, struct Bucket buckets[]) {
    for (int i = 0; i < n; i++) {
        int index = arr[i] * BUCKET_COUNT / (MAX + 1);
        buckets[index].arr[buckets[index].count++] = arr[i];
    }
}

// Function to perform insertion sort on a bucket
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to merge the sorted buckets
void mergeBuckets(int arr[], struct Bucket buckets[]) {
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].arr[j];
        }
    }
}

// Main function to implement Bucket Sort
void bucketSort(int arr[], int n) {
    struct Bucket buckets[BUCKET_COUNT];

    // Initialize buckets
    initializeBuckets(buckets);
    
    // Distribute elements into buckets
    distributeToBuckets(arr, n, buckets);

    // Sort individual buckets and merge them
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].arr, buckets[i].count);
        }
    }
    mergeBuckets(arr, buckets);
    
    // Free allocated memory
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i].arr);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int arr[MAX];
    
    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d integers between 0 and %d:\n", n, MAX);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] > MAX) {
            printf("Invalid input: Element must be in range 0 to %d.\n", MAX);
            return 1;
        }
    }

    printf("Unsorted array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}