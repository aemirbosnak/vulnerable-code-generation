//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int generate_random_number(int min, int max);
int generate_random_array(int size, int min, int max);
void print_array(int arr[], int size);
void merge_sort(int arr[], int size);
void merge(int arr[], int left, int mid, int right);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }

    // Fill the array with random numbers
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = generate_random_number(1, 100);
    }

    // Print the unsorted array
    printf("\nUnsorted Array:\n");
    print_array(arr, size);

    // Sort the array using merge sort
    merge_sort(arr, size);

    // Print the sorted array
    printf("\nSorted Array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}

// Function to generate a random number within a given range
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random array of a given size and range
int generate_random_array(int size, int min, int max) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        arr[i] = generate_random_number(min, max);
    }

    return arr;
}

// Function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform merge sort on an array
void merge_sort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;
    int *left_half = (int *)malloc(mid * sizeof(int));
    int *right_half = (int *)malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left_half[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right_half[i - mid] = arr[i];
    }

    merge_sort(left_half, mid);
    merge_sort(right_half, size - mid);

    merge(arr, left_half, mid, right_half);

    free(left_half);
    free(right_half);
}

// Function to merge two sorted halves of an array
void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            arr[k++] = arr[i++];
        } else {
            arr[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        arr[k++] = arr[i++];
    }
}