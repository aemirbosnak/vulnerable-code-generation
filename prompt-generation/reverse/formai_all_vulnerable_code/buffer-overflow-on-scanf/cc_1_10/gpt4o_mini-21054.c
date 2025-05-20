//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define BUCKET_COUNT 10

// Function prototypes
void bucketSort(int arr[], int n);
void initializeBuckets(int buckets[BUCKET_COUNT][MAX_ELEMENTS], int bucketSizes[BUCKET_COUNT]);
void insertIntoBucket(int buckets[BUCKET_COUNT][MAX_ELEMENTS], int bucketSizes[BUCKET_COUNT], int num);
void sortBucket(int bucket[], int size);
void printSortedArray(int arr[], int n);
void generateRandomNumbers(int arr[], int n, int range);

int main() {
    int arr[MAX_ELEMENTS];
    int n;

    printf("Enter the number of elements you want to sort (max %d): ", MAX_ELEMENTS);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX_ELEMENTS) {
        printf("Invalid number of elements. Exiting...\n");
        return 1;
    }

    // Generate random numbers to sort
    generateRandomNumbers(arr, n, 100);
    printf("Unsorted Array: ");
    printSortedArray(arr, n);
    
    bucketSort(arr, n);

    printf("Sorted Array: ");
    printSortedArray(arr, n);

    return 0;
}

void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    int buckets[BUCKET_COUNT][MAX_ELEMENTS] = {0};
    int bucketSizes[BUCKET_COUNT] = {0};

    // Initialize buckets
    initializeBuckets(buckets, bucketSizes);

    // Distribute input array values into buckets
    for(int i = 0; i < n; i++) {
        insertIntoBucket(buckets, bucketSizes, arr[i]);
    }

    // Sort individual buckets
    for(int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            sortBucket(buckets[i], bucketSizes[i]);
        }
    }

    // Concatenate the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void initializeBuckets(int buckets[BUCKET_COUNT][MAX_ELEMENTS], int bucketSizes[BUCKET_COUNT]) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        bucketSizes[i] = 0;
    }
}

void insertIntoBucket(int buckets[BUCKET_COUNT][MAX_ELEMENTS], int bucketSizes[BUCKET_COUNT], int num) {
    int bucketIndex = num / (100 / BUCKET_COUNT);
    if (bucketIndex >= BUCKET_COUNT) bucketIndex = BUCKET_COUNT - 1; // Handle edge case

    buckets[bucketIndex][bucketSizes[bucketIndex]] = num;
    bucketSizes[bucketIndex]++;
}

void sortBucket(int bucket[], int size) {
    // Simple bubble sort for small buckets
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (bucket[j] > bucket[j + 1]) {
                int temp = bucket[j];
                bucket[j] = bucket[j + 1];
                bucket[j + 1] = temp;
            }
        }
    }
}

void printSortedArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateRandomNumbers(int arr[], int n, int range) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }
}