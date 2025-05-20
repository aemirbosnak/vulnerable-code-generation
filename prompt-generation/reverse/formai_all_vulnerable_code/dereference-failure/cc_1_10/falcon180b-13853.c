//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to print an array
void print_array(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to create a new bucket
void create_bucket(int arr[], int n, int *bucket, int capacity) {
    for (int i = 0; i < n; i++) {
        int index = arr[i] * capacity / MAX_SIZE;
        if (index < 0) index = 0;
        if (index >= capacity) index = capacity - 1;
        bucket[index]++;
    }
}

// Function to sort the array using bucket sort
void bucket_sort(int arr[], int n) {
    int capacity = MAX_SIZE / 10;
    int *bucket = (int *)malloc(capacity * sizeof(int));
    if (bucket == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    create_bucket(arr, n, bucket, capacity);
    int i = 0;
    for (int j = 0; j < capacity; j++) {
        while (bucket[j] > 0) {
            arr[i] = j * 10;
            i++;
            bucket[j]--;
        }
    }
    free(bucket);
}

// Function to main
int main() {
    int arr[] = { 10, 5, 3, 8, 2, 6, 4, 7, 9, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("Sorted array: ");
    print_array(arr, n);
    return 0;
}