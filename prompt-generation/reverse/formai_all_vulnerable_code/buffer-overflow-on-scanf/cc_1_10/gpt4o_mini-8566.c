//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a bucket
typedef struct Bucket {
    int *arr;     // Array to hold bucket elements
    int size;     // Size of the bucket (number of elements)
    int capacity; // Capacity of the bucket
} Bucket;

// Function to initialize a bucket
Bucket* create_bucket(int initial_capacity) {
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->capacity = initial_capacity;
    bucket->size = 0;
    bucket->arr = (int*)malloc(bucket->capacity * sizeof(int));
    return bucket;
}

// Function to insert an element to a bucket
void insert_bucket(Bucket* bucket, int value) {
    if (bucket->size == bucket->capacity) {
        // Resize the bucket if necessary
        bucket->capacity *= 2;
        bucket->arr = (int*)realloc(bucket->arr, bucket->capacity * sizeof(int));
    }
    bucket->arr[bucket->size++] = value;
}

// Function to sort a single bucket
void insertion_sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function for bucket sort
void bucket_sort(int* input, int n, int bucket_count) {
    // Create an array of buckets
    Bucket** buckets = (Bucket**)malloc(bucket_count * sizeof(Bucket*));
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = create_bucket(10); // Each bucket starts with an initial capacity of 10
    }

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = input[i] * bucket_count / (n + 1); // Bucket index calculation
        if (bucket_index >= bucket_count) {
            bucket_index = bucket_count - 1; // Ensure last element goes into the last bucket
        }
        insert_bucket(buckets[bucket_index], input[i]);
    }

    // Sort individual buckets
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        insertion_sort(buckets[i]->arr, buckets[i]->size);
        for (int j = 0; j < buckets[i]->size; j++) {
            input[index++] = buckets[i]->arr[j];
        }
        free(buckets[i]->arr);
        free(buckets[i]);
    }
    free(buckets);
}

// Function to display the array
void display_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 1; // Exit if invalid
    }

    int* arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting:\n");
    display_array(arr, n);

    // Perform bucket sort
    int bucket_count = 5; // Change this value to adjust bucket count
    bucket_sort(arr, n, bucket_count);

    printf("Array after sorting:\n");
    display_array(arr, n);

    free(arr); // Free the dynamically allocated memory
    return 0;
}