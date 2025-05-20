//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an array
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate a random array of integers
void generate_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

// Function to perform quicksort on an array
void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get array size from user input
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate random array of integers
    srand(time(NULL));
    generate_array(arr, size);

    // Print unsorted array
    printf("Unsorted array:\n");
    print_array(arr, size);

    // Perform quicksort on the array
    quicksort(arr, 0, size - 1);

    // Print sorted array
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}