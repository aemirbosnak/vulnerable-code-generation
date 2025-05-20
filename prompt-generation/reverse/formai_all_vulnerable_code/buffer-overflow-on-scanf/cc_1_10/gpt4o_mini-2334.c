//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearchWithHint(int arr[], int size, int target) {
    int last_found = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Linear Search: Found %d at index %d\n", target, i);
            last_found = i;
            break;
        } else {
            printf("Linear Search: Checking element %d at index %d\n", arr[i], i);
        }
    }
    return last_found;
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Binary Search: Found %d at index %d\n", target, mid);
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

int combinedSearch(int arr[], int size, int target) {
    // First, attempt linear search with hints
    printf("Starting combined search...\n");
    int found_index = linearSearchWithHint(arr, size, target);
    
    // If not found, proceed with binary search
    if (found_index == -1) {
        printf("Linear search failed, sorting array for binary search...\n");
        sortArray(arr, size);
        found_index = binarySearch(arr, 0, size - 1, target);

        if (found_index == -1) {
            printf("Combined Search: %d not found in array.\n", target);
        }
    }

    return found_index;
}

int main() {
    int size, target;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
  
    inputArray(arr, size);

    printf("Enter the number you wish to search for: ");
    scanf("%d", &target);

    int result = combinedSearch(arr, size, target);
    if (result != -1) {
        printf("Number %d was found at index: %d\n", target, result);
    } else {
        printf("Number %d was not found in the array.\n", target);
    }

    free(arr);
    return EXIT_SUCCESS;
}