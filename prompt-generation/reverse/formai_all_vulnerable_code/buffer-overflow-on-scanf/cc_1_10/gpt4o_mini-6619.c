//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10 // Maximum number of buckets
#define MAX_ELEMENTS 100 // Maximum elements per bucket

// Structure to hold individual buckets
typedef struct Bucket {
    int arr[MAX_ELEMENTS];
    int size;
} Bucket;

// Function to initialize a bucket
void initBucket(Bucket *b) {
    b->size = 0;
}

// Function to add an element to the bucket
void addToBucket(Bucket *b, int num) {
    if(b->size < MAX_ELEMENTS) {
        b->arr[b->size++] = num; // Add number and increment size
    }
}

// Function to sort a bucket using insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0..i-1], that are
        // greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    // Step 1: Create buckets
    Bucket buckets[MAX_BUCKETS];
    for (int i = 0; i < MAX_BUCKETS; i++) {
        initBucket(&buckets[i]);
    }

    // Step 2: Distribute array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * MAX_BUCKETS / (n + 1); // Normalize index
        if (bucketIndex >= MAX_BUCKETS) bucketIndex = MAX_BUCKETS - 1; // Handle max case
        addToBucket(&buckets[bucketIndex], arr[i]);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < MAX_BUCKETS; i++) {
        if (buckets[i].size > 0) {
            insertionSort(buckets[i].arr, buckets[i].size);
        }
    }

    // Step 4: Concatenate the buckets into original array
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].arr[j];
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to orchestrate sorting
int main() {
    printf("🎨 Welcome to the Bucket Sort Display! 🎨\n");

    // Step 1: Prepare a randomized array of integers
    int n;
    printf("✨ Enter the number of elements to sort: ");
    scanf("%d", &n);
    if(n > MAX_ELEMENTS) {
        printf("🚫 Exceeds maximum elements limit (%d). Sorting with %d elements instead.\n", MAX_ELEMENTS, MAX_ELEMENTS);
        n = MAX_ELEMENTS;
    }
    int arr[MAX_ELEMENTS];

    // Seed random number generator
    srand((unsigned int)time(NULL));
    printf("✨ Generating an array of random integers...\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random integers from 0 to 99
    }

    // Step 2: Display the unsorted array
    printf("🌊 Unsorted array: ");
    printArray(arr, n);

    // Step 3: Perform the bucket sort
    bucketSort(arr, n);

    // Step 4: Display the sorted array
    printf("🌟 Sorted array: ");
    printArray(arr, n);

    printf("🎉 Sorting completed successfully! 🎉\n");
    return 0;
}