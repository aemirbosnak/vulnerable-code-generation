//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100
#define BUCKET_SIZE 10

void initializeBuckets(int bucketCount, float buckets[][MAX_NUM], int bucketElements[]) {
    for (int i = 0; i < bucketCount; i++) {
        bucketElements[i] = 0; // Initialize the bucket size to 0
        for (int j = 0; j < MAX_NUM; j++) {
            buckets[i][j] = 0; // Initialize all elements in the bucket to 0
        }
    }
}

void bucketSort(float array[], int n) {
    float buckets[BUCKET_SIZE][MAX_NUM];
    int bucketElements[BUCKET_SIZE];
    int i, j;
    
    initializeBuckets(BUCKET_SIZE, buckets, bucketElements);
    
    // Determine the factor to decide bucket placement
    float maxValue = array[0];
    float minValue = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > maxValue) maxValue = array[i];
        if (array[i] < minValue) minValue = array[i];
    }

    float range = maxValue - minValue;
    float bucketRange = range / BUCKET_SIZE;

    // Distribute array elements into buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = (array[i] - minValue) / bucketRange;
        if (bucketIndex >= BUCKET_SIZE) {
            bucketIndex = BUCKET_SIZE - 1; // Ensure the index is within bounds
        }
        buckets[bucketIndex][bucketElements[bucketIndex]] = array[i];
        bucketElements[bucketIndex]++;
    }

    // Sort individual buckets using a simple insertion sort
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 1; j < bucketElements[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate sorted buckets back into the original array
    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < bucketElements[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }
}

void printArray(float array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    float array[MAX_NUM];
    int n;

    printf("Enter number of elements (max %d): ", MAX_NUM);
    scanf("%d", &n);
    
    if (n > MAX_NUM || n <= 0) {
        printf("Invalid number of elements. Please enter a positive integer up to %d.\n", MAX_NUM);
        return EXIT_FAILURE;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    printf("Array before sorting:\n");
    printArray(array, n);

    bucketSort(array, n);

    printf("Array after sorting:\n");
    printArray(array, n);

    return EXIT_SUCCESS;
}