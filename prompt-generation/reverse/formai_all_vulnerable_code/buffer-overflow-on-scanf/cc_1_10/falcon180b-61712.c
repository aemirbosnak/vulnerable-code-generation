//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

// Function to initialize the array with random values
void init_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to sort the array using bubble sort
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get array size from user
    printf("Enter array size: ");
    scanf("%d", &size);

    // Initialize the array with random values
    init_array(arr, size);

    // Sort the array using bubble sort
    bubble_sort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}