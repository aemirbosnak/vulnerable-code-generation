//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10  // Number of buckets
#define MAX_VALUES 100  // Maximum number of elements in the array
#define VALUE_RANGE 100 // Range of values (0 to VALUE_RANGE-1)

// Function to create and initialize buckets
void initializeBuckets(int *buckets[MAX_BUCKETS]) {
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = malloc(MAX_VALUES * sizeof(int));
        if (buckets[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for bucket %d\n", i);
            exit(EXIT_FAILURE);
        }
        memset(buckets[i], 0, MAX_VALUES * sizeof(int));  // Initialize bucket
    }
}

// Function to perform insertion sort on each bucket
void insertionSort(int *bucket, int n) {
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
void bucketSort(int *array, int n) {
    int *buckets[MAX_BUCKETS];
    initializeBuckets(buckets);
    
    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (array[i] * MAX_BUCKETS) / VALUE_RANGE;  // Bucket index
        if (index >= MAX_BUCKETS) {
            index = MAX_BUCKETS - 1;  // Handle max range
        }
        buckets[index][++buckets[index][0]] = array[i];  // Add to bucket
    }

    // Sort each bucket and store sorted elements back to array
    int k = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        if (buckets[i][0] > 0) {
            insertionSort(buckets[i] + 1, buckets[i][0]);  // Sort the bucket
            for (int j = 1; j <= buckets[i][0]; j++) {
                array[k++] = buckets[i][j];  // Collect sorted values
            }
        }
    }

    // Free allocated memory for buckets
    for (int i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i]);
    }
}

// Function to print the array
void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function to test the bucket sort
int main() {
    int n;
    printf("Enter number of elements (up to %d): ", MAX_VALUES);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_VALUES) {
        fprintf(stderr, "Invalid number of elements!\n");
        return EXIT_FAILURE;
    }

    int array[MAX_VALUES];
    printf("Enter %d integers (between 0 and %d):\n", n, VALUE_RANGE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] < 0 || array[i] >= VALUE_RANGE) {
            fprintf(stderr, "Value must be between 0 and %d\n", VALUE_RANGE - 1);
            return EXIT_FAILURE;
        }
    }

    printf("Original array:\n");
    printArray(array, n);

    bucketSort(array, n);

    printf("Sorted array:\n");
    printArray(array, n);

    return 0;
}