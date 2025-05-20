//Falcon-180B DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate a random number between min and max
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random array of integers
void randArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = randInt(1, 100);
    }
}

// Function to check if an array is sorted in ascending order
int isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int size) {
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

    srand(time(NULL));

    // Prompt user for array size
    printf("Enter array size (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Generate random array
    randArray(arr, size);

    // Sort array in ascending order
    bubbleSort(arr, size);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}