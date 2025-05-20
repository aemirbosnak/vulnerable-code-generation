//Falcon-180B DATASET v1.0 Category: Educational ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to fill an array with random numbers
void fillArray(int arr[], int size) {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandomNumber(1, 100);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    // Get the size of the array from the user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Fill the array with random numbers
    fillArray(arr, size);

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort the array using bubble sort
    bubbleSort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}