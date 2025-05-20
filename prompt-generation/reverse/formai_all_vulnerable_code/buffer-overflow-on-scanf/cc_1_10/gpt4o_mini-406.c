//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform Linear Search
int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // return index if found
        }
    }
    return -1; // return -1 if not found
}

// Function to perform Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // return index if found
        }
        if (arr[mid] < target) {
            left = mid + 1; // move to right half
        } else {
            right = mid - 1; // move to left half
        }
    }
    return -1; // return -1 if not found
}

// Function to generate a random array and sort it
void generateSortedArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // random numbers between 0 - 99
    }

    // Sort the array using simple Bubble Sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0)); // Seed random number generator

    int arr[MAX_SIZE];
    int size = 20; // Size of the array

    // Generate a sorted array
    generateSortedArray(arr, size);

    // Display the array
    displayArray(arr, size);

    int target;
    printf("Enter a number to search: ");
    scanf("%d", &target);

    // Perform Linear Search
    int linearIndex = linearSearch(arr, size, target);
    if (linearIndex != -1) {
        printf("Linear Search: Number found at index %d\n", linearIndex);
    } else {
        printf("Linear Search: Number not found\n");
    }

    // Perform Binary Search
    int binaryIndex = binarySearch(arr, size, target);
    if (binaryIndex != -1) {
        printf("Binary Search: Number found at index %d\n", binaryIndex);
    } else {
        printf("Binary Search: Number not found\n");
    }

    return 0;
}