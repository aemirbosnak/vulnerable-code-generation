//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target
        }
    }
    return -1; // Return -1 if not found
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index of the target
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        }
        else {
            right = mid - 1; // Target is in the left half
        }
    }
    return -1; // Return -1 if not found
}

void fillArrayWithRandomNumbers(int arr[], int size, int lower, int upper) {
    for (int i = 0; i < size; i++) {
        arr[i] = lower + rand() % (upper - lower + 1);
    }
}

void sortArray(int arr[], int size) {
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

int main() {
    int array[MAX_SIZE];
    int size, target;

    // Get size of the array from user
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Fill array with random numbers and display
    fillArrayWithRandomNumbers(array, size, 1, 100);
    displayArray(array, size);

    // Perform linear search
    printf("Enter a target value to linear search: ");
    scanf("%d", &target);
    int linearResult = linearSearch(array, size, target);
    if (linearResult != -1) {
        printf("Linear Search: %d found at index %d\n", target, linearResult);
    } else {
        printf("Linear Search: %d not found\n", target);
    }

    // Sort the array for binary search
    sortArray(array, size);
    displayArray(array, size);

    // Perform binary search
    printf("Enter a target value to binary search: ");
    scanf("%d", &target);
    int binaryResult = binarySearch(array, size, target);
    if (binaryResult != -1) {
        printf("Binary Search: %d found at index %d\n", target, binaryResult);
    } else {
        printf("Binary Search: %d not found\n", target);
    }

    return 0;
}