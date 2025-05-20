//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Structure to represent a bucket
typedef struct Bucket {
    int *array;
    int size;
} Bucket;

// Function prototypes
void bucketSort(float arr[], int n);
void printArray(float arr[], int n);
int compare(const void *a, const void *b);

// Main function
int main() {
    float arr[MAX];
    int n, i;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements
    printf("Enter %d elements (floating-point):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    Bucket *buckets = (Bucket *)malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        buckets[i].array = (int *)malloc(n * sizeof(int));
        buckets[i].size = 0;
    }

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]); // Find the appropriate bucket index
        buckets[index].array[buckets[index].size++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        if (buckets[i].size > 0) {
            qsort(buckets[i].array, buckets[i].size, sizeof(float), compare);
        }
    }

    // Concatenate all sorted buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (buckets[i].size > 0) {
            for (int j = 0; j < buckets[i].size; j++) {
                arr[index++] = buckets[i].array[j];
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(buckets[i].array);
    }
    free(buckets);
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    float floatA = *(const float *)a;
    float floatB = *(const float *)b;
    if (floatA < floatB) return -1;
    if (floatA > floatB) return 1;
    return 0;
}