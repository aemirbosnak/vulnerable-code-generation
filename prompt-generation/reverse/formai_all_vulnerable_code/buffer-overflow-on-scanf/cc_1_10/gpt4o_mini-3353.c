//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

typedef struct {
    int *values;
    int size;
} Bucket;

// Function prototypes
void initializeBuckets(Bucket *buckets, int bucketCount);
void freeBuckets(Bucket *buckets, int bucketCount);
void bucketSort(int *array, int n, int bucketCount);
void printArray(int *array, int size);
void generateRandomNumbers(int *array, int size, int range);

int main() {
    int n, bucketCount;
    int *array;

    // User input for number of elements and number of buckets
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    printf("Enter the number of buckets: ");
    scanf("%d", &bucketCount);
    
    if (n > MAX_NUMBERS) {
        printf("Please enter a number of elements less than or equal to %d\n", MAX_NUMBERS);
        return EXIT_FAILURE;
    }
    
    // Allocate memory for the array
    array = (int *)malloc(n * sizeof(int));
    if (!array) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    // Generate random numbers
    generateRandomNumbers(array, n, 100); // Random numbers in the range [0, 99]
    printf("Unsorted array:\n");
    printArray(array, n);

    // Perform bucket sort
    bucketSort(array, n, bucketCount);
    printf("Sorted array:\n");
    printArray(array, n);

    // Free allocated memory
    free(array);
    
    return EXIT_SUCCESS;
}

void initializeBuckets(Bucket *buckets, int bucketCount) {
    for (int i = 0; i < bucketCount; i++) {
        buckets[i].values = (int *)malloc(MAX_NUMBERS * sizeof(int));
        buckets[i].size = 0;
    }
}

void freeBuckets(Bucket *buckets, int bucketCount) {
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i].values);
    }
}

void bucketSort(int *array, int n, int bucketCount) {
    if (n <= 0) return;

    Bucket *buckets = (Bucket *)malloc(bucketCount * sizeof(Bucket));
    initializeBuckets(buckets, bucketCount);
    
    // Determine the range of values
    int maxValue = array[0];
    int minValue = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxValue) maxValue = array[i];
        if (array[i] < minValue) minValue = array[i];
    }

    // Distribute the input array's elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (bucketCount * (array[i] - minValue)) / (maxValue - minValue + 1);
        buckets[bucketIndex].values[buckets[bucketIndex].size++] = array[i];
    }

    // Sort each bucket and place them back into the original array
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        // Sort the individual bucket using simple insertion sort
        for (int j = 1; j < buckets[i].size; j++) {
            int temp = buckets[i].values[j];
            int k = j - 1;
            while (k >= 0 && buckets[i].values[k] > temp) {
                buckets[i].values[k + 1] = buckets[i].values[k];
                k--;
            }
            buckets[i].values[k + 1] = temp;
        }
        
        // Copy the sorted bucket back into the original array
        for (int j = 0; j < buckets[i].size; j++) {
            array[index++] = buckets[i].values[j];
        }
    }

    // Free bucket memory
    freeBuckets(buckets, bucketCount);
    free(buckets);
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void generateRandomNumbers(int *array, int size, int range) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % range;
    }
}