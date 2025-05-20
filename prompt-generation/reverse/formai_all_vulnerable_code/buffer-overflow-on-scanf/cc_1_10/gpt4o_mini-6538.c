//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_COUNT 10   // Number of buckets
#define MAX_NUMS 100      // Maximum number of numbers

// Function prototypes
void bucketSort(float arr[], int n);
void insertionSort(float arr[], int n);
float findMax(float arr[], int n);
void printArray(float arr[], int n);

int main() {
    float arr[MAX_NUMS];
    int n;

    printf("Enter the number of elements to sort (max %d): ", MAX_NUMS);
    scanf("%d", &n);

    if (n > MAX_NUMS || n <= 0) {
        printf("Invalid number of elements. Exiting...\n");
        return 1;
    }

    printf("Enter %d floating-point numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Unsorted array:\n");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

void bucketSort(float arr[], int n) {
    // Create buckets
    float **buckets = malloc(BUCKET_COUNT * sizeof(float *));
    int *bucketSizes = malloc(BUCKET_COUNT * sizeof(int));
    
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = malloc(n * sizeof(float));
        bucketSizes[i] = 0;  // Initialize sizes of buckets
    }

    // Find the maximum element to determine the bucket index
    float maxValue = findMax(arr, n);

    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_COUNT * arr[i] / (maxValue + 1));
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1; // Put in last bucket
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets and merge them back into arr
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free allocated memory for buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
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

float findMax(float arr[], int n) {
    float max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}