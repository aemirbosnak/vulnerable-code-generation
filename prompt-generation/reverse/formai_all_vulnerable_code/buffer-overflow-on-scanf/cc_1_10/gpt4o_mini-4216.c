//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 100
#define BUCKET_COUNT 10

typedef struct {
    float *values;
    int count;
} Bucket;

void initializeBuckets(Bucket *buckets, int size) {
    for (int i = 0; i < size; i++) {
        buckets[i].values = malloc(MAX_VALUES * sizeof(float));
        buckets[i].count = 0;
    }
}

void freeBuckets(Bucket *buckets, int size) {
    for (int i = 0; i < size; i++) {
        free(buckets[i].values);
    }
}

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

void bucketSort(float arr[], int n) {
    // Create buckets
    Bucket buckets[BUCKET_COUNT];
    initializeBuckets(buckets, BUCKET_COUNT);

    // Distribute input values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_COUNT * arr[i]);
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1;
        }
        buckets[bucketIndex].values[buckets[bucketIndex].count] = arr[i];
        buckets[bucketIndex].count++;
    }

    // Sort each bucket and merge them
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].values, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].values[j];
            }
        }
    }

    // Free allocated memory for buckets
    freeBuckets(buckets, BUCKET_COUNT);
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    float arr[MAX_VALUES];

    printf("Enter the number of elements (up to %d): ", MAX_VALUES);
    scanf("%d", &n);
    if(n > MAX_VALUES || n <= 0) {
        printf("Invalid number of elements. Please enter a value between 1 and %d.\n", MAX_VALUES);
        return -1;
    }

    printf("Enter %d floating point numbers (values between 0 and 1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        if (arr[i] < 0.0 || arr[i] > 1.0) {
            printf("Input should be between 0 and 1. Please restart the program.\n");
            return -1;
        }
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}