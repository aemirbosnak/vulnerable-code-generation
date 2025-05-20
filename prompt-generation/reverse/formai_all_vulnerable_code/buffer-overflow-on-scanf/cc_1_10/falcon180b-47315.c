//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure for each element in the array
typedef struct {
    int data;
    char name[20];
} Element;

// Define the function prototypes
void createArray(Element arr[], int size);
void displayArray(Element arr[], int size);
int binarySearch(Element arr[], int size, int target);

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Create the array with random elements
    Element arr[size];
    createArray(arr, size);

    // Display the array
    printf("\nThe array is:\n");
    displayArray(arr, size);

    // Get the target element from the user
    int target;
    printf("\nEnter the target element to search for: ");
    scanf("%d", &target);

    // Perform binary search and display the result
    int result = binarySearch(arr, size, target);
    if (result == -1) {
        printf("\nThe element %d is not in the array.\n", target);
    } else {
        printf("\nThe element %d is at index %d.\n", target, result);
    }

    return 0;
}

// Function to create the array with random elements
void createArray(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        sprintf(arr[i].name, "Element %d", i + 1);
    }
}

// Function to display the array
void displayArray(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s (%d)\n", arr[i].name, arr[i].data);
    }
}

// Function to perform binary search
int binarySearch(Element arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].data == target) {
            return mid;
        } else if (arr[mid].data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}