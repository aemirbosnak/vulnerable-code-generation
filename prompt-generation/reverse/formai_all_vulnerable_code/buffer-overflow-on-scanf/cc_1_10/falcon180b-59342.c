//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two elements
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// Function to perform sorting
void sort(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Initialize the array with random values
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(arr, size);

    // Sort the array
    sort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}