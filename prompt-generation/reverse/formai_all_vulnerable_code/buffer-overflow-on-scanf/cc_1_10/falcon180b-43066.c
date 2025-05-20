//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the array

// Function to search for a given element in the array
int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to sort the array in ascending order
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE], size, element;

    // Prompt user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt user to enter the element to search for
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    // Search for the element in the array
    int index = search(arr, size, element);

    // Print the result of the search
    if (index == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    return 0;
}