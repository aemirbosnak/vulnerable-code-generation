//Falcon-180B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
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

// Function to perform quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to generate a random array of integers
void generate_array(int arr[], int size) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];

    // Get size of array from user
    printf("Enter the size of the array: ");
    scanf("%d", &arr[0]);

    // Check if array size is valid
    if (arr[0] <= 0 || arr[0] > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Generate random array
    generate_array(arr, arr[0]);

    // Sort the array
    quicksort(arr, 0, arr[0] - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, arr[0]);

    return 0;
}