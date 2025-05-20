//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Function to sort an array using the insertion sort algorithm
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
void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    // Create buckets
    int i, j;
    float **buckets = (float **)malloc(BUCKET_COUNT * sizeof(float *));
    int *bucketSizes = (int *)calloc(BUCKET_COUNT, sizeof(int));

    for (i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }

    // Put array elements into the appropriate buckets
    for (i = 0; i < n; i++) {
        int bi = (int)(BUCKET_COUNT * arr[i]); // Determine the bucket index
        if (bi >= BUCKET_COUNT) {
            bi = BUCKET_COUNT - 1; // Keep index in bounds
        }
        buckets[bi][bucketSizes[bi]] = arr[i];
        bucketSizes[bi]++;
    }

    // Sort each bucket and collect the results
    int index = 0;
    for (i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free allocated memory
    for (i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Function to get input from the user
void getInput(float arr[], int n) {
    printf("Enter %d floating numbers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%f", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter numbers only.\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    int n;

    printf("Enter the number of elements you want to sort: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of elements.\n");
        return EXIT_FAILURE;
    }

    float *arr = (float *)malloc(n * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    getInput(arr, n);
    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}