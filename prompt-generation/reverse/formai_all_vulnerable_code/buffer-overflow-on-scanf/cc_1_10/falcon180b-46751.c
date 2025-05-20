//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform binary search on the array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size-1;
    int mid;

    while(left <= right) {
        mid = left + (right-left)/2;

        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] < target) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }

    return -1; // Target not found
}

// Function to perform linear search on the array
int linearSearch(int arr[], int size, int target) {
    int i;

    for(i=0; i<size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[MAX_SIZE];
    int size, target, choice, result;

    // Prompt the user to enter the array elements
    printf("Enter the array elements:\n");
    scanf("%d", &size);

    if(size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter the array elements:\n");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt the user to choose the search algorithm
    printf("Choose the search algorithm:\n");
    printf("1. Binary search\n");
    printf("2. Linear search\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter the target element:\n");
        scanf("%d", &target);
        result = binarySearch(arr, size, target);
    } else if(choice == 2) {
        printf("Enter the target element:\n");
        scanf("%d", &target);
        result = linearSearch(arr, size, target);
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    if(result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at position %d.\n", result);
    }

    return 0;
}