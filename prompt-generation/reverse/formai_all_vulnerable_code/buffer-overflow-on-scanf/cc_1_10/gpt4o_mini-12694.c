//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define BUCKET_COUNT 10

// Function to create an array of buckets
typedef struct {
    float *values;
    int count;
} Bucket;

// Helper function to initialize a bucket
void initBucket(Bucket *bucket) {
    bucket->values = (float *)malloc(MAX_SIZE * sizeof(float));
    bucket->count = 0;
}

// Function to add a value to a bucket
void addToBucket(Bucket *bucket, float value) {
    bucket->values[bucket->count++] = value;
}

// Function to sort a single bucket
void insertionSort(float arr[], int n) {
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

// Function to perform bucket sort
void bucketSort(float array[], int n) {
    if (n <= 0) return;

    // Create an array of buckets
    Bucket buckets[BUCKET_COUNT];
    for (int i = 0; i < BUCKET_COUNT; i++) {
        initBucket(&buckets[i]);
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_COUNT * array[i]); // Normalize value to get buck index
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1;
        }
        addToBucket(&buckets[bucketIndex], array[i]);
    }

    // Sort individual buckets and concatenate results
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].values, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                array[index++] = buckets[i].values[j];
            }
        }
        free(buckets[i].values); // Free allocated memory for values
    }
}

// Function to display the array
void displayArray(float array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    float array[MAX_SIZE];
    int n;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Please enter a valid number of elements.\n");
        return 1;
    }

    printf("Enter %d float numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    printf("Original array:\n");
    displayArray(array, n);

    bucketSort(array, n);

    printf("Sorted array:\n");
    displayArray(array, n);

    return 0;
}