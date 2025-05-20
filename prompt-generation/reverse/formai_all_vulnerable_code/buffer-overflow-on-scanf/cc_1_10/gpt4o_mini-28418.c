//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10  // Define the number of buckets
#define MAX_VALUE 100.0 // Maximum value of elements to be sorted

// Structure to represent each bucket
typedef struct Bucket {
    float *values;
    int count;
} Bucket;

// Function to create a bucket
Bucket* create_bucket() {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->values = (float *)malloc(BUCKET_SIZE * sizeof(float));
    bucket->count = 0;
    return bucket;
}

// Function to free a bucket
void free_bucket(Bucket *bucket) {
    free(bucket->values);
    free(bucket);
}

// Function to perform insertion sort on a bucket
void insertion_sort(float *array, int n) {
    for (int i = 1; i < n; i++) {
        float key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucket_sort(float *array, int n) {
    if (n <= 0) return;

    // Create buckets
    Bucket **buckets = (Bucket **)malloc(BUCKET_SIZE * sizeof(Bucket *));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = create_bucket();
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)(array[i] * BUCKET_SIZE / MAX_VALUE);
        if (bucket_index >= BUCKET_SIZE) bucket_index = BUCKET_SIZE - 1; // Edge case
        buckets[bucket_index]->values[buckets[bucket_index]->count++] = array[i];
    }

    // Sort individual buckets and collect sorted values
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (buckets[i]->count > 0) {
            insertion_sort(buckets[i]->values, buckets[i]->count);
            for (int j = 0; j < buckets[i]->count; j++) {
                array[index++] = buckets[i]->values[j];
            }
        }
        // Free the memory allocated for each bucket
        free_bucket(buckets[i]);
    }

    // Free the bucket array
    free(buckets);
}

// Function to print an array
void print_array(float *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic array allocation
    float *array = (float *)malloc(n * sizeof(float));

    // Input values
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    // Perform bucket sort
    bucket_sort(array, n);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(array, n);

    // Free the dynamically allocated array
    free(array);

    return 0;
}