//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 1000

// Function to sort the array in ascending order
void sort(int arr[], int size) {
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

// Function to search for an element in the array
int search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[MAX_SIZE], size, target;

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order
    sort(arr, size);

    // Prompt the user to enter the target element
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Search for the target element in the array
    int index = search(arr, size, target);

    if (index == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d!\n", index);
    }

    return 0;
}