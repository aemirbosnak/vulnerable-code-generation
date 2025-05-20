//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUCKETS 1000
#define MAX_RANGE 1000000

// Function to generate a random number between min and max (inclusive)
int rand_in_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to sort an array using bucket sort
void bucket_sort(int arr[], int n) {
    int i, j, count[MAX_BUCKETS] = {0};
    int *bucket[MAX_BUCKETS];

    // Create empty buckets
    for (i = 0; i < MAX_BUCKETS; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * n);
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        int bucket_index = arr[i] / MAX_RANGE;
        bucket[bucket_index][count[bucket_index]++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < MAX_BUCKETS; i++) {
        for (j = 1; j < count[i]; j++) {
            int key = bucket[i][j];
            int k = j - 1;

            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = key;
        }
    }

    // Merge sorted buckets back into original array
    for (i = 0; i < n; i++) {
        int bucket_index = arr[i] / MAX_RANGE;
        arr[i] = bucket[bucket_index][--count[bucket_index]];
    }

    // Free memory used by buckets
    for (i = 0; i < MAX_BUCKETS; i++) {
        free(bucket[i]);
    }
}

// Function to generate an array of random integers
void generate_array(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        arr[i] = rand_in_range(1, MAX_RANGE);
    }
}

// Function to print an array of integers
void print_array(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int n, i;

    // Get array size from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Initialize array with random integers
    int arr[n];
    generate_array(arr, n);

    // Print unsorted array
    printf("Unsorted array:\n");
    print_array(arr, n);

    // Sort array using bucket sort
    bucket_sort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}