//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100
#define SORTING_ALGORITHM "Crazy Sort"

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to sort the array using the chosen algorithm
void sort(int arr[], int low, int high) {
    int i, j, pivot;

    // Choose a pivot element from the middle of the array
    pivot = arr[((low + high) / 2)];

    // Partition the array into three parts:
    // 1. Elements less than the pivot
    // 2. Elements equal to the pivot
    // 3. Elements greater than the pivot
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            // Swap with the first element greater than pivot
            swap(arr, i, low);
            low++;
        } else if (arr[i] > pivot) {
            // Swap with the last element less than pivot
            swap(arr, i, high);
            high--;
        }
    }

    // Recursively sort the two partitioned arrays
    sort(arr, low, high);
    sort(arr, low + 1, high - low - 1);
}

// Main function to test the sorting algorithm
int main() {
    int arr[MAX_ARRAY_SIZE];
    int i, j, n;
    char choice;

    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Generate a random array of integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Ask the user to choose the sorting algorithm
    printf("Choose a sorting algorithm: ");
    scanf(" %c", &choice);

    // Sort the array based on the chosen algorithm
    if (choice == 'C') {
        sort(arr, 0, n - 1);
    } else if (choice == 'S') {
        sort(arr, 0, n - 1);
    } else {
        printf("Invalid choice! Please try again.\n");
        return 1;
    }

    // Print the sorted array
    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}