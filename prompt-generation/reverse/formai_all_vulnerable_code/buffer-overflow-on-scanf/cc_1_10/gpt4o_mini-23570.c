//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100.0 // Define the maximum value for input
#define BUCKET_COUNT 10  // Number of buckets

// Function to initialize the buckets
void initialize_buckets(int bucket_count, int *bucket_sizes, int **buckets) {
    for (int i = 0; i < bucket_count; i++) {
        bucket_sizes[i] = 0;
        buckets[i] = (int *)malloc(sizeof(int) * 100); // Allocate memory for a maximum of 100 elements
        if (buckets[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for bucket %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
}

// Function to distribute elements into the buckets
void bucket_sort(float *array, int n) {
    int bucket_sizes[BUCKET_COUNT];
    int *buckets[BUCKET_COUNT];

    // Initialize the buckets
    initialize_buckets(BUCKET_COUNT, bucket_sizes, buckets);

    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)(BUCKET_COUNT * array[i] / MAX_VALUE);
        if (bucket_index >= BUCKET_COUNT) {
            bucket_index = BUCKET_COUNT - 1; // Adjust if the value is at max
        }
        buckets[bucket_index][bucket_sizes[bucket_index]++] = array[i] * 100; // Scale to integer
    }

    // Sort each bucket and concatenate the results
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucket_sizes[i] > 0) {
            // Sort the current bucket using simple insertion sort
            for (int j = 1; j < bucket_sizes[i]; j++) {
                int key = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
        }
    }

    // Collect the sorted buckets back into the array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            array[index++] = (float)buckets[i][j] / 100; // Scale back to float
        }
    }

    // Free allocated memory for buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
}

// Function to print the array
void print_array(float *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "Number of elements must be positive.\n");
        return 1;
    }

    float *array = (float *)malloc(sizeof(float) * n);
    if (array == NULL) {
        fprintf(stderr, "Memory allocation for array failed.\n");
        return 1;
    }

    printf("Enter %d elements (between 0 and %.2f):\n", n, MAX_VALUE);
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
        if (array[i] < 0 || array[i] > MAX_VALUE) {
            fprintf(stderr, "Element %d is out of bounds. It must be between 0 and %.2f.\n", i + 1, MAX_VALUE);
            free(array);
            return 1;
        }
    }

    printf("Original array:\n");
    print_array(array, n);

    // Call the bucket sort function
    bucket_sort(array, n);

    printf("Sorted array:\n");
    print_array(array, n);

    free(array);
    return 0;
}