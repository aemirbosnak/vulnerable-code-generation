//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print array
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bubble sort
void bubble_sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE], size;

    // Get array size from user
    printf("Enter array size: ");
    scanf("%d", &size);

    // Get array elements from user
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    print_array(arr, size);

    // Sort array using bubble sort
    bubble_sort(arr, size);

    // Print sorted array
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}