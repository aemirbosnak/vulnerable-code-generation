//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure for each element in the array
typedef struct {
    int data;
    int index;
} Element;

// Function to swap two elements in the array
void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(Element* arr, int low, int high) {
    Element pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform quicksort on the array
void quicksort(Element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to search for an element in the array
int search(Element* arr, int size, int target) {
    quicksort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        if (arr[i].data == target) {
            return arr[i].index;
        }
    }
    return -1;
}

// Main function
int main() {
    Element arr[MAX_SIZE];
    int n, target;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    // Get the target element from the user
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Perform the search
    int result = search(arr, n, target);

    // Print the result
    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}