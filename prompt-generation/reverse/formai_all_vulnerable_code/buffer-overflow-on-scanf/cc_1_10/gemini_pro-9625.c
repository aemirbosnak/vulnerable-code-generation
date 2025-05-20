//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Structure to hold a bucket
struct bucket {
    int count;
    int *values;
};

// Function to create a bucket
struct bucket *create_bucket() {
    struct bucket *b = malloc(sizeof(struct bucket));
    b->count = 0;
    b->values = malloc(sizeof(int) * 10);
    return b;
}

// Function to insert a value into a bucket
void insert_into_bucket(struct bucket *b, int value) {
    if (b->count == 10) {
        b->values = realloc(b->values, sizeof(int) * (b->count + 1));
    }
    b->values[b->count] = value;
    ++b->count;
}

// Function to sort a bucket
void sort_bucket(struct bucket *b) {
    for (int i = 0; i < b->count - 1; ++i) {
        for (int j = i + 1; j < b->count; ++j) {
            if (b->values[i] > b->values[j]) {
                int temp = b->values[i];
                b->values[i] = b->values[j];
                b->values[j] = temp;
            }
        }
    }
}

// Function to perform bucket sort
void bucket_sort(int *arr, int n) {
    // Create an array of buckets
    struct bucket *buckets[10];
    for (int i = 0; i < 10; ++i) {
        buckets[i] = create_bucket();
    }

    // Insert each value into a bucket
    for (int i = 0; i < n; ++i) {
        int bucket_index = arr[i] / 10;
        insert_into_bucket(buckets[bucket_index], arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < 10; ++i) {
        sort_bucket(buckets[i]);
    }

    // Concatenate the sorted buckets into the output array
    int index = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < buckets[i]->count; ++j) {
            arr[index] = buckets[i]->values[j];
            ++index;
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < 10; ++i) {
        free(buckets[i]->values);
        free(buckets[i]);
    }
}

// Function to print an array
void print_array(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the input array
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}