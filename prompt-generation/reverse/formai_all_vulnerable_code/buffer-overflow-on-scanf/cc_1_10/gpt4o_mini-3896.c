//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

void displayMenu() {
    printf("1. Enter Elements\n");
    printf("2. Search Element\n");
    printf("3. Exit\n");
}

void enterElements(int arr[], int *size) {
    printf("Enter number of elements: ");
    scanf("%d", size);
    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void sortArray(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
    printf("Array sorted successfully.\n");
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // found
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // not found
}

void searchElement(int arr[], int size) {
    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
}

int main() {
    int arr[100], size = 0;
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enterElements(arr, &size);
                sortArray(arr, size);
                break;
            case 2:
                if (size == 0) {
                    printf("Array is empty. Please enter elements first.\n");
                } else {
                    searchElement(arr, size);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}