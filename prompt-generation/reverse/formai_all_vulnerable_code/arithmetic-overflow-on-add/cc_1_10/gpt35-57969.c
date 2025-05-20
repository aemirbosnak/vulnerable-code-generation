//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to perform the bucket sort
void bucket_sort(int arr[], int n, int max_val) {

    // Initialize an array of buckets
    int* bucket = (int*) malloc(max_val * sizeof(int));
    memset(bucket, 0, max_val * sizeof(int));

    // Populate the buckets with the data
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Write the contents of the buckets back to the array
    int idx = 0;
    for (int i = 0; i < max_val; i++) {
        while (bucket[i] > 0) {
            arr[idx++] = i;
            bucket[i]--;
        }
    }

    // Free the memory allocated for the bucket array
    free(bucket);
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program
int main() {
    // Initialize the array
    int arr[] = {8, 1, 4, 3, 6, 5, 7, 2};

    // Get the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Get the maximum value in the data set
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Perform the bucket sort
    bucket_sort(arr, n, max_val + 1);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}