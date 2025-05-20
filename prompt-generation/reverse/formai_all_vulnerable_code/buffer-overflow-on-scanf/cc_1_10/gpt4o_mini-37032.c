//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: genius
#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 20

void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size); // Optimal block size
    int prev = 0;

    // Finding the block where the target is present (if it is present)
    while (arr[step < size ? step : size - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            printf("Target not found in the array.\n");
            return -1;
        }
    }

    // Linear search within the block
    for (int i = prev; i < (step < size ? step : size); i++) {
        if (arr[i] == target) {
            return i; // Target found
        }
    }

    printf("Target not found in the array.\n");
    return -1;
}

void inputSortedArray(int arr[], int size) {
    printf("Please enter %d sorted integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        while (1) { // Ensure only integers are imported
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. Enter an integer: ");
                while (getchar() != '\n'); // Clear invalid input
            } else {
                break;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int target, result;
    
    // Input the sorted array
    inputSortedArray(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE);

    // User inputs the target number to search
    printf("Enter the number you want to search: ");
    while (1) { // Input validation loop for target number
        if (scanf("%d", &target) != 1) {
            printf("Invalid input. Enter an integer: ");
            while (getchar() != '\n'); // Clear invalid input
        } else {
            break;
        }
    }

    // Performing the jump search
    result = jumpSearch(arr, ARRAY_SIZE, target);

    // Displaying the result
    if (result != -1) {
        printf("Number %d found at index %d.\n", target, result);
    }

    return 0;
}