//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>

void printArray(int arr[], int size) {
    printf("Array elements: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int linearSearch(int arr[], int size, int target) {
    printf("Starting linear search for %d in the array...\n", target);
    
    for (int i = 0; i < size; i++) {
        printf("Checking index %d, value %d...\n", i, arr[i]);

        if (arr[i] == target) {
            printf("Found %d at index %d!\n", target, i);
            return i; // Element found, return index
        }
    }
    
    printf("%d not found in the array.\n", target);
    return -1; // Element not found
}

int main() {
    int arr[100], size;
    
    printf("Enter the number of elements in the array (max 100): ");
    scanf("%d", &size);
    
    if (size < 1 || size > 100) {
        printf("Invalid size. Please enter a number between 1 and 100.\n");
        return 1;
    }

    printf("Please enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printArray(arr, size);

    int target;
    printf("Enter the integer to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("The integer %d was found at index %d.\n", target, result);
    } else {
        printf("The integer %d was not found in the array.\n", target);
    }

    printf("End of linear search program.\n");
    return 0;
}