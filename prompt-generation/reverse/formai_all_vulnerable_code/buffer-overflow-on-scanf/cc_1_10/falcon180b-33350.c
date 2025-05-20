//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to search for an element in the array
int search(int arr[], int size, int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to display the array
void display(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    int result = search(arr, size, element);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}