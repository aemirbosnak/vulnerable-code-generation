//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to perform Insertion Sort on each individual bucket
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    // Step 1: Create n empty buckets
    int i;
    int bucketCount = 10; // Number of buckets
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));

    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucketSizes[i] = 0;
    }

    // Step 2: Insert elements into their respective buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * bucketCount);
        if (bucketIndex >= bucketCount) {
            bucketIndex = bucketCount - 1;
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = (int)(arr[i] * 100); // Store as integers
    }

    // Step 3: Sort individual buckets and concatenate them
    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = (float)(buckets[i][j]) / 100.0; // Convert back to float
            }
        }
    }

    // Step 4: Clean up dynamic memory
    for (i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(float arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("]\n");
}

// Function to generate random float numbers
void generateRandomFloats(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (float)rand() / (float)(RAND_MAX); // random float between 0 and 1
    }
}

// Main function to drive the program
int main() {
    int n;

    printf("Welcome to the Creative Bucket Sort Program!\n");
    printf("Enter the number of random float numbers you want to sort: ");
    scanf("%d", &n);

    float *arr = (float *)malloc(n * sizeof(float));
    generateRandomFloats(arr, n);

    printf("Generated array of random floats:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array of floats:\n");
    printArray(arr, n);

    // Free allocated memory for the float array
    free(arr);
    return 0;
}