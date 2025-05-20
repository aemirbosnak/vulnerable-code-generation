//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10  // Size of individual buckets

// Structure to represent a Bucket
typedef struct Bucket {
    float *values;  // Array to store the values in the bucket
    int count;      // Number of elements in the bucket
} Bucket;

// Function to create a bucket
Bucket *create_bucket() {
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

// Function to insert an element into a bucket
void insert_bucket(Bucket *bucket, float value) {
    if (bucket->count % BUCKET_SIZE == 0) {
        bucket->values = (float *)realloc(bucket->values,
            (bucket->count + BUCKET_SIZE) * sizeof(float));
    }
    bucket->values[bucket->count++] = value;
}

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

// Function to perform bucket sort
void bucket_sort(float *arr, int n) {
    if (n <= 0) return;

    // Step 1: Create buckets
    Bucket **buckets = (Bucket **)malloc(n * sizeof(Bucket *));
    for (int i = 0; i < n; i++) {
        buckets[i] = create_bucket();
    }

    // Step 2: Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)(n * arr[i]); // Finding the appropriate bucket index
        insert_bucket(buckets[bucket_index], arr[i]);
    }

    // Step 3: Sort each bucket and concatenate results
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (buckets[i]->count > 0) {
            qsort(buckets[i]->values, buckets[i]->count, sizeof(float), compare);
            for (int j = 0; j < buckets[i]->count; j++) {
                arr[index++] = buckets[i]->values[j];
            }
        }
    }

    // Step 4: Free the allocated memory
    for (int i = 0; i < n; i++) {
        free_bucket(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void print_array(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function to test the bucket sort implementation
int main() {
    int n;

    // Ask the user for the number of elements and read into an array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    float *arr = (float *)malloc(n * sizeof(float));

    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    print_array(arr, n);

    // Perform bucket sort
    bucket_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    // Free the allocated memory for the array
    free(arr);

    return 0;
}