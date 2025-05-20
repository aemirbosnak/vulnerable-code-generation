//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure for each element in the array
typedef struct {
    int data;
    int index;
} element;

// Function to swap two elements in the array
void swap(element *a, element *b) {
    element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(element *arr, int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    while (low <= high) {
        while (arr[low].data < pivot) {
            low++;
        }
        while (arr[high].data > pivot) {
            high--;
        }
        if (low <= high) {
            swap(&arr[low], &arr[high]);
            low++;
            high--;
        }
    }
    return low;
}

// Function to perform quick sort on the array
void quickSort(element *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(element *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

// Main function
int main() {
    element arr[MAX_SIZE];
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    // Perform quick sort on the array
    quickSort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}