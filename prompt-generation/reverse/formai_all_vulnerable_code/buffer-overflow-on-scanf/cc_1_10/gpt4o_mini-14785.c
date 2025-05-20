//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Function to get the maximum value in the array
float getMax(float arr[], int n) {
    float max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform insertion sort on a bucket
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

// Function to perform the Bucket Sort
void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    // Create buckets
    float max = getMax(arr, n);
    float min = 0.0; // Assuming non-negative numbers
    float range = (max - min) / BUCKET_COUNT;

    // Create an array of pointers for each bucket
    float **buckets = (float **)malloc(BUCKET_COUNT * sizeof(float *));
    int *bucketSizes = (int *)calloc(BUCKET_COUNT, sizeof(int));

    // Initialize each bucket
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / range;
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1; // Put in the last bucket
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // Concatenate all buckets into arr
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]); // Free memory of each bucket
    }
    free(buckets); // Free the bucket array
    free(bucketSizes); // Free the sizes array
}

// Main function to test the Bucket Sort implementation
int main() {
    printf("Welcome to the Bucket Sort Adventure! 🎉\n");
    printf("Let's sort some numbers!\n");

    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    float *arr = (float *)malloc(n * sizeof(float));

    printf("Awesome! Now, enter %d floating-point numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    printf("Let's sort these numbers using Bucket Sort! 🪣\n");
    bucketSort(arr, n);

    printf("Hooray! Your sorted numbers are:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    // Clean up memory
    free(arr);

    printf("Thanks for using Bucket Sort! Have a great day! 🌟\n");
    return 0;
}