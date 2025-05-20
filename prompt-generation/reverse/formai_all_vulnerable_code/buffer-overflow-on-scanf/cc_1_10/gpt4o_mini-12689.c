//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 1000
#define BUCKET_COUNT 10

// Structure to define a Bucket
typedef struct Bucket {
    int *array;       // Dynamic array to hold values
    int count;       // Count of elements in the bucket
} Bucket;

// Function to create and initialize buckets
Bucket* createBuckets(int count) {
    Bucket *buckets = (Bucket*)malloc(count * sizeof(Bucket));
    for (int i = 0; i < count; i++) {
        buckets[i].count = 0;
        buckets[i].array = (int*)malloc(sizeof(int) * MAX_VALUE);
    }
    return buckets;
}

// Function to free the allocated memory for buckets
void freeBuckets(Bucket *buckets, int count) {
    for (int i = 0; i < count; i++) {
        free(buckets[i].array);
    }
    free(buckets);
}

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

// Function to perform Bucket Sort
void bucketSort(int *array, int n) {
    // Create buckets
    Bucket *buckets = createBuckets(BUCKET_COUNT);

    // Distributing the elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = array[i] * BUCKET_COUNT / (MAX_VALUE + 1);
        buckets[bucketIndex].array[buckets[bucketIndex].count] = array[i];
        buckets[bucketIndex].count++;
    }

    // Sorting each bucket and merging them
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (buckets[i].count > 0) {
            // Sort bucket
            qsort(buckets[i].array, buckets[i].count, sizeof(int), compare);
            // Merging back into the original array
            memcpy(&array[index], buckets[i].array, 
                   sizeof(int) * buckets[i].count);
            index += buckets[i].count;
        }
    }

    // Free buckets
    freeBuckets(buckets, BUCKET_COUNT);
}

// Main function to execute the program
int main() {
    int n;
    printf("Enter the number of elements to sort (0 - %d): ", MAX_VALUE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VALUE) {
        printf("Please enter a valid number of elements.\n");
        return 1;
    }

    int *array = (int*)malloc(n * sizeof(int));
    
    // Generating random numbers for the array
    printf("Your random numbers are:\n");
    for (int i = 0; i < n; i++) {
        array[i] = rand() % MAX_VALUE;
        printf("%d ", array[i]);
    }
    printf("\n");

    // Perform Bucket Sort
    bucketSort(array, n);

    // Outputting the sorted array
    printf("Sorted numbers are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Freeing the allocated memory for the array
    free(array);

    return 0;
}