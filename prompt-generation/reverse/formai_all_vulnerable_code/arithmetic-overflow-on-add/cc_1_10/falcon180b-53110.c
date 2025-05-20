//Falcon-180B DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition an array using the last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform quicksort on an array
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to generate a random array of integers
int* generate_array(int size, int min, int max) {
    int* arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }

    return arr;
}

int main() {
    int size, min, max;

    // Get user input for array size, minimum and maximum values
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the minimum value: ");
    scanf("%d", &min);

    printf("Enter the maximum value: ");
    scanf("%d", &max);

    // Generate a random array of integers
    int* arr = generate_array(size, min, max);

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using quicksort
    quicksort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}