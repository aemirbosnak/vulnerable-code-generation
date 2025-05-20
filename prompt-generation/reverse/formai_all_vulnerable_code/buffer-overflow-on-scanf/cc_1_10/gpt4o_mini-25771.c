//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to perform Modified Jump Search
int modifiedJumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;

    // Finding the block where the element is present
    while (arr[step - 1] < target && step < size) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; // Target not found
        }
    }

    // Performing linear search in the identified block
    for (int i = prev; i < step && i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target element
        }
    }

    return -1; // Target not found
}

// Function to sort an array (simple bubble sort for demonstration)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size, target, result;

    // Input size of the array
    printf("Enter number of elements in array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return -1;
    }

    // Input elements of the array
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array before searching
    bubbleSort(arr, size);
    displayArray(arr, size);

    // Input the target element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform Modified Jump Search
    result = modifiedJumpSearch(arr, size, target);

    // Display result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}