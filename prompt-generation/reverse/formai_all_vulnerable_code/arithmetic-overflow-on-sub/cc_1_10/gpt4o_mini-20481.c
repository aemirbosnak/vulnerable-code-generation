//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform linear search
int linear_search(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // return the index of the target
        }
    }
    return -1; // if target not found
}

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            return mid; // return the index of the target
        }
        else if(arr[mid] < target) {
            left = mid + 1; // search right half
        }
        else {
            right = mid - 1; // search left half
        }
    }
    return -1; // if target not found
}

// Function to print an array
void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array using bubble sort
void bubble_sort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to get user input
void get_input(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int size, choice, target, result;

    // Get the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if(arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Get user input
    get_input(arr, size);
    
    // Display the array
    printf("You entered the array: ");
    print_array(arr, size);

    // Ask user for sorting
    printf("Would you like to sort the array before searching? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if(choice == 1) {
        bubble_sort(arr, size);
        printf("Sorted array: ");
        print_array(arr, size);
    }

    // Ask user for the target to search
    printf("Enter the target integer to search: ");
    scanf("%d", &target);

    // Perform linear search
    result = linear_search(arr, size, target);
    if(result != -1) {
        printf("Linear Search: Element %d found at index %d.\n", target, result);
    } else {
        printf("Linear Search: Element %d not found.\n", target);
    }

    // Perform binary search
    result = binary_search(arr, size, target);
    if(result != -1) {
        printf("Binary Search: Element %d found at index %d.\n", target, result);
    } else {
        printf("Binary Search: Element %d not found.\n", target);
    }

    // Free allocated memory
    free(arr);

    return 0;
}