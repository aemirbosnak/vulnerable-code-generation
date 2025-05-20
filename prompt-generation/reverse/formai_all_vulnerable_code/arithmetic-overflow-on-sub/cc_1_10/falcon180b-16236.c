//Falcon-180B DATASET v1.0 Category: Recursive ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Recursive function to generate permutations of an array
void permute(int arr[], int left, int right) {
    static int next[MAX] = {0}; // Initialize next[] with 0 for first call
    int i;

    // Base case: all elements have been placed
    if (left == right) {
        printArray(arr, right + 1);
        return;
    }

    // Recursive case: permute the remaining elements
    for (i = left; i <= right; i++) {
        if (next[i] == 0) { // Check if this element has not been placed yet
            next[i] = 1; // Mark this element as placed
            arr[left] = i; // Place this element in the first position
            permute(arr, left + 1, right); // Permute the remaining elements
        }
    }
}

int main() {
    int arr[MAX], n;

    // Get the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Generate all permutations of the array
    permute(arr, 0, n - 1);

    return 0;
}