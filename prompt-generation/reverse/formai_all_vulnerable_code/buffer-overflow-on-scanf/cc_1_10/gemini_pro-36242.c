//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to create a bucket
struct bucket {
    int count;
    int *elements;
};

// Function to create an array of buckets
struct bucket* create_buckets(int n) {
    struct bucket* buckets = (struct bucket*)malloc(sizeof(struct bucket) * n);
    for (int i = 0; i < n; i++) {
        buckets[i].count = 0;
        buckets[i].elements = (int*)malloc(sizeof(int) * n);
    }
    return buckets;
}

// Function to insert an element into a bucket
void insert_into_bucket(struct bucket* buckets, int element, int bucket_index) {
    buckets[bucket_index].elements[buckets[bucket_index].count] = element;
    buckets[bucket_index].count++;
}

// Function to sort the elements in a bucket
void sort_bucket(struct bucket* bucket) {
    for (int i = 0; i < bucket->count - 1; i++) {
        for (int j = 0; j < bucket->count - i - 1; j++) {
            if (bucket->elements[j] > bucket->elements[j + 1]) {
                int temp = bucket->elements[j];
                bucket->elements[j] = bucket->elements[j + 1];
                bucket->elements[j + 1] = temp;
            }
        }
    }
}

// Function to sort an array using bucket sort
void bucket_sort(int* arr, int n) {
    // Create an array of buckets
    struct bucket* buckets = create_buckets(n);

    // Insert the elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)((double)arr[i] / n * (n - 1));
        insert_into_bucket(buckets, arr[i], bucket_index);
    }

    // Sort the elements in each bucket
    for (int i = 0; i < n; i++) {
        sort_bucket(&buckets[i]);
    }

    // Concatenate the elements from the buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index] = buckets[i].elements[j];
            index++;
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < n; i++) {
        free(buckets[i].elements);
    }
    free(buckets);
}

// Function to print an array
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the input array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("The sorted array is: ");
    print_array(arr, n);

    return 0;
}