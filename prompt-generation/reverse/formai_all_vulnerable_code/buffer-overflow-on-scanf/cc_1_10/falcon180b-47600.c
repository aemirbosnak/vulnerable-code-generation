//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to generate random integers between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print an array of integers
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucket_sort(int arr[], int size) {
    int max_val = arr[0];
    int min_val = arr[0];

    // Find the minimum and maximum values in the array
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calculate the range of the array
    int range = max_val - min_val;

    // Calculate the number of buckets
    int num_buckets = range / 10;

    // Create an array of empty buckets
    int buckets[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = 0;
    }

    // Place each element in the correct bucket
    for (int i = 0; i < size; i++) {
        int bucket_index = (arr[i] - min_val) / 10;
        buckets[bucket_index]++;
    }

    // Place the elements back in the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = min_val + i * 10;
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Generate a random array of integers
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        arr[i] = rand_int(1, 100);
    }

    // Print the original array
    printf("Original array:\n");
    print_array(arr, size);

    // Sort the array using bucket sort
    bucket_sort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}