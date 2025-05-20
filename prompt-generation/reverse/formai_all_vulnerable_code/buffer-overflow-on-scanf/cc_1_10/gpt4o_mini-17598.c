//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void fillArray(int arr[], int size);
void displayArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
int compare(const void *a, const void *b);

int main() {
    int arr[MAX_SIZE];
    int size, target, choice, result;

    printf("Welcome to the C Searching Algorithm Example Program!\n");
    printf("How many elements do you want to input (max %d)? ", MAX_SIZE);
    scanf("%d", &size);

    if(size <= 0 || size > MAX_SIZE) {
        printf("Invalid size. Please restart the program and enter a valid size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    fillArray(arr, size);
    displayArray(arr, size);

    printf("Choose search method:\n1. Linear Search\n2. Binary Search\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    switch(choice) {
        case 1:
            result = linearSearch(arr, size, target);
            if(result != -1) {
                printf("Linear Search: Number %d found at index %d.\n", target, result);
            } else {
                printf("Linear Search: Number %d not found in the array.\n", target);
            }
            break;
        case 2:
            // First, we need to sort the array for binary search
            qsort(arr, size, sizeof(int), compare);
            displayArray(arr, size);
            result = binarySearch(arr, size, target);
            if(result != -1) {
                printf("Binary Search: Number %d found at index %d.\n", target, result);
            } else {
                printf("Binary Search: Number %d not found in the array.\n", target);
            }
            break;
        default:
            printf("Invalid choice. Please start the program again and select a valid option.\n");
            return 1;
    }

    return 0;
}

// Function to fill array with user inputs
void fillArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    printf("Current Array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // return index if target is found
        }
    }
    return -1; // return -1 if not found
}

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == target) {
            return mid; // return index if target is found
        }
        if(arr[mid] < target) {
            left = mid + 1; // move to the right half
        } else {
            right = mid - 1; // move to the left half
        }
    }
    return -1; // return -1 if not found
}

// Compare function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}