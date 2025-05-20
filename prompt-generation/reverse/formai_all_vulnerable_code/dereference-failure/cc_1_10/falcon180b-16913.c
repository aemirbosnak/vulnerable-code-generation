//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

// Function to generate a random integer between 0 and range-1
int rand_int(int range) {
    return rand() % range;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_size = MAX_RANGE / max_val;
    int* buckets = malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucket_idx = arr[i] / bucket_size;
        buckets[bucket_idx]++;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        int j = 0;
        while (j < buckets[i]) {
            arr[j] = i * bucket_size;
            j++;
        }
    }

    free(buckets);
}

// Function to print an array
void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL));

    int n = rand_int(MAX_SIZE);
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand_int(MAX_RANGE);
    }

    printf("Original array:\n");
    print_arr(arr, n);

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    print_arr(arr, n);

    return 0;
}