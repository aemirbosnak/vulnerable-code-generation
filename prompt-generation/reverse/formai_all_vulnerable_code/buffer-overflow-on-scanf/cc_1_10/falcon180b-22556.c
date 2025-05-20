//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random array of integers
void rand_arr(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand_num(1, MAX_SIZE);
    }
}

// Function to print an array of integers
void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for a value in a sorted array using binary search
int binary_search(int arr[], int size, int value) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to search for a value in a sorted array using linear search
int linear_search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE], size, value;

    // Prompt the user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate a random array of integers
    rand_arr(arr, size);

    // Print the original array
    printf("Original array:\n");
    print_arr(arr, size);

    // Prompt the user for the value to search for
    printf("Enter the value to search for: ");
    scanf("%d", &value);

    // Perform binary search
    int index = binary_search(arr, size, value);
    if (index == -1) {
        printf("Value not found.\n");
    } else {
        printf("Value found at index %d.\n", index);
    }

    // Perform linear search
    index = linear_search(arr, size, value);
    if (index == -1) {
        printf("Value not found.\n");
    } else {
        printf("Value found at index %d.\n", index);
    }

    return 0;
}