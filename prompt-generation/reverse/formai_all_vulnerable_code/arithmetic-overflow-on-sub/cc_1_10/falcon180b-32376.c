//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generate_random_number(int min, int max);
void bubble_sort(int arr[], int size);

int main() {
    int size, i;
    int *arr;

    // Get array size from user
    printf("Enter array size: ");
    scanf("%d", &size);

    // Allocate memory for array
    arr = (int *)malloc(size * sizeof(int));

    // Populate array with random numbers
    for (i = 0; i < size; i++) {
        arr[i] = generate_random_number(1, 100);
    }

    // Sort array using bubble sort
    bubble_sort(arr, size);

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory allocated for array
    free(arr);

    return 0;
}

// Function to generate a random number between min and max (inclusive)
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to sort an array using bubble sort
void bubble_sort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}