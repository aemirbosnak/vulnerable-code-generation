//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000 // Maximum number of elements
#define BUCKET_SIZE 10 // Size of each bucket

// Function prototypes
void bucketSort(float arr[], int n);
void printArray(float arr[], int n);
float getMax(float arr[], int n);
void sortBucket(float bucket[], int n);

// Main function
int main() {
    int n, i;
    float arr[MAX];

    printf("Welcome to the Retro Bucket Sort Program!\n");
    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("Number exceeds the maximum limit of %d. Exiting...\n", MAX);
        return 1;
    }
    
    printf("Enter %d elements (between 0 and 1):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        // Ensure the input is between 0 and 1
        if (arr[i] < 0.0 || arr[i] > 1.0) {
            printf("Please enter a value between 0 and 1 only.\n");
            return 1;
        }
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0;
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    int i, j, index;
    int bucketCount = (int)(ceil(sqrt(n)));
    float **buckets = malloc(bucketCount * sizeof(float*));
    int *bucketSizes = malloc(bucketCount * sizeof(int));

    // Initialize buckets
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = malloc(BUCKET_SIZE * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Add elements to buckets
    for (i = 0; i < n; i++) {
        index = (int) (arr[i] * bucketCount);
        if (index >= bucketCount) {
            index = bucketCount - 1;
        }
        if (bucketSizes[index] >= BUCKET_SIZE) {
            printf("Bucket overflow: Increase bucket size!\n");
            exit(1);
        }
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // Sort buckets and put them back into the original array
    int pos = 0;
    for (i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            sortBucket(buckets[i], bucketSizes[i]);
            for (j = 0; j < bucketSizes[i]; j++) {
                arr[pos++] = buckets[i][j];
            }
        }
        free(buckets[i]); // Free each bucket after use
    }

    free(buckets); // Free bucket array
    free(bucketSizes); // Free sizes array
}

// Function to sort individual buckets using simple insertion sort
void sortBucket(float bucket[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = bucket[i];
        j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Utility function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}