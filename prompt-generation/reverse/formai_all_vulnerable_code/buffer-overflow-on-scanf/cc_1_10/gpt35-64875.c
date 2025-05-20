//FormAI DATASET v1.0 Category: Random ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Recursive function to generate a random array of integers */ 
void generateRandomArray(int arr[], int size, int max) {
    if (size == 0) return;
    arr[size-1] = rand() % max;
    generateRandomArray(arr, size-1, max);
}

/* Binary search algorithm recursive implementation */ 
int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, mid+1, high, target);
    else return binarySearchRecursive(arr, low, mid-1, target);
}

/* Main function */
int main() {
    srand(time(NULL));

    // Generate a random array of 10 integers between 0 and 99
    int arr[10];
    generateRandomArray(arr, 10, 100);

    // Print the randomly generated array
    printf("Randomly generated array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bubble sort algorithm
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Prompt the user for a search target
    int target;
    printf("Enter a target integer between 0 and 99: ");
    scanf("%d", &target);

    // Perform a binary search on the sorted array
    int index = binarySearchRecursive(arr, 0, 9, target);

    // Print the search result
    if (index != -1) {
        printf("Target integer %d located at index %d.\n", target, index);
    } else {
        printf("Target integer %d not found in the array.\n", target);
    }

    return 0;
}