//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_RANGE 100
#define NUM_BUCKETS 10

// A structure representing each bucket
struct Bucket {
    float *arr;
    int count;
};

// Function to create buckets
struct Bucket* createBuckets(int numBuckets) {
    struct Bucket* buckets = (struct Bucket*) malloc(numBuckets * sizeof(struct Bucket));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].arr = (float*) malloc(MAX_RANGE * sizeof(float));
        buckets[i].count = 0;
    }
    return buckets;
}

// Function to free memory allocated to buckets
void freeBuckets(struct Bucket* buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].arr);
    }
    free(buckets);
}

// Function to perform insertion sort on a given array
void insertionSort(float *arr, int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// The main Bucket Sort algorithm
void bucketSort(float *arr, int n) {
    // Create buckets
    struct Bucket* buckets = createBuckets(NUM_BUCKETS);

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * NUM_BUCKETS);
        if (index >= NUM_BUCKETS) {
            index = NUM_BUCKETS - 1;
        }
        buckets[index].arr[buckets[index].count++] = arr[i];
    }

    // Sort each bucket and concatenate them
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].arr, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].arr[j];
            }
        }
    }

    // Free memory allocated to buckets
    freeBuckets(buckets, NUM_BUCKETS);
}

// Function to print the array
void printArray(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate the Bucket Sort algorithm
int main() {
    int n;

    // Get the number of elements in the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    float *arr = (float*) malloc(n * sizeof(float));

    // Get array elements from the user
    printf("Enter %d floating-point numbers between 0 and 1:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        if (arr[i] < 0 || arr[i] > 1) {
            printf("Please enter a number between 0 and 1.\n");
            free(arr);
            return 1;
        }
    }

    // Perform bucket sort on the array
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    // Free allocated memory
    free(arr);

    return 0;
}