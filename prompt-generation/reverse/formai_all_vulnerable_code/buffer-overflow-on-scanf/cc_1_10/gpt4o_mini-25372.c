//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define BUCKET_COUNT 10

// Function to get the max value in an array
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// Function to perform insertion sort on a bucket
void insertionSort(int bucket[], int n) {
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int array[], int n) {
    // Step 1: Create buckets
    int buckets[BUCKET_COUNT][MAX];
    int bucketSize[BUCKET_COUNT];

    // Initialize buckets
    for (int i = 0; i < BUCKET_COUNT; i++)
        bucketSize[i] = 0;

    // Step 2: Distribute input array values into buckets
    int max = getMax(array, n);
    for (int i = 0; i < n; i++) {
        int bucketIndex = (array[i] * BUCKET_COUNT) / (max + 1);
        buckets[bucketIndex][bucketSize[bucketIndex]++] = array[i];
    }

    // Step 3: Sort each bucket and gather them together
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSize[i] > 0) {
            insertionSort(buckets[i], bucketSize[i]);
            for (int j = 0; j < bucketSize[i]; j++)
                array[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Perform bucket sort
    bucketSort(array, n);

    // Print the sorted output
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free allocated memory
    free(array);
    return 0;
}