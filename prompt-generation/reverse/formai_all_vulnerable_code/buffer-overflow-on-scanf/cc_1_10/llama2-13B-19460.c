//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers
void sort(int arr[], int low, int high) {
    // Base case: If the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two halves
    int mid = (low + high) / 2;
    swap(arr[low], arr[mid]);
    swap(arr[high], arr[low]);

    // Recursively sort the two halves
    sort(arr, low, mid);
    sort(arr, mid + 1, high);

    // Combine the two sorted halves
    swap(arr[low], arr[high]);
}

int main() {
    int arr[MAX_LENGTH];
    int i, j, n;

    // Read the array of integers from the user
    printf("Enter an array of integers (%d elements): ", MAX_LENGTH);
    for (i = 0; i < MAX_LENGTH; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    sort(arr, 0, MAX_LENGTH - 1);

    // Print the sorted array
    printf("The sorted array is: ");
    for (i = 0; i < MAX_LENGTH; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}