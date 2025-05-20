//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using bucket sort algorithm
void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Create an array of buckets
    int* buckets = (int*) malloc(max_val * sizeof(int));
    for (int i = 0; i < max_val; i++) {
        buckets[i] = 0;
    }

    // Place elements in their respective buckets
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // Concatenate the buckets to form the sorted array
    int j = 0;
    for (int i = 0; i < max_val; i++) {
        while (buckets[i] > 0) {
            arr[j++] = i;
            buckets[i]--;
        }
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL));

    // Define the size of the array and its elements
    int n = rand_int(1, 10);
    int arr[n];

    // Fill the array with random integers
    for (int i = 0; i < n; i++) {
        arr[i] = rand_int(1, 100);
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(arr, n);

    // Sort the array using bucket sort algorithm
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}