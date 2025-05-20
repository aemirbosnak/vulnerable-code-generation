//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 // Number of buckets

// Function prototypes
void bucketSort(float arr[], int n);
void insertionSort(float arr[], int n);
int getBucketIndex(float value, int bucketCount, float minValue, float range);
void displayArray(float arr[], int n);

int main() {
    int n, i;
    float *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (float *)malloc(n * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the elements (floating point numbers):\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Unsorted array:\n");
    displayArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    displayArray(arr, n);

    free(arr);
    return 0;
}

// Function to implement Bucket Sort
void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    // Find the maximum and minimum elements
    float maxValue = arr[0];
    float minValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) maxValue = arr[i];
        if (arr[i] < minValue) minValue = arr[i];
    }

    float range = maxValue - minValue;
    float **buckets = (float **)malloc(BUCKET_SIZE * sizeof(float *));
    int *bucketCounts = (int *)malloc(BUCKET_SIZE * sizeof(int));

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketCounts[i] = 0;
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = getBucketIndex(arr[i], BUCKET_SIZE, minValue, range);
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    // Sort each bucket and concatenate results
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (bucketCounts[i] > 0) {
            insertionSort(buckets[i], bucketCounts[i]);
            for (int j = 0; j < bucketCounts[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketCounts);
}

// Function to sort an array using Insertion Sort
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

// Function to get the index of the bucket
int getBucketIndex(float value, int bucketCount, float minValue, float range) {
    if (range == 0) return 0; // All elements are the same
    return (int)((value - minValue) * bucketCount / range);
}

// Function to display the array
void displayArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}