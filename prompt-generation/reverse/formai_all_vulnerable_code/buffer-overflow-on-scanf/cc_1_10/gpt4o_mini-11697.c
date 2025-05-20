//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void linearSearch(int arr[], int size, int target);
void binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);
void displayArray(int arr[], int size);
void printMenu();

int main() {
    int arr[MAX_SIZE];
    int size = 0, choice, target;

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    sortArray(arr, size);
    printf("Sorted Array: ");
    displayArray(arr, size);

    while (1) {
        printMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to search (Linear Search): ");
                scanf("%d", &target);
                linearSearch(arr, size, target);
                break;
            case 2:
                printf("Enter the number to search (Binary Search): ");
                scanf("%d", &target);
                binarySearch(arr, size, target);
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

void linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index %d (Linear Search).\n", target, i);
            return;
        }
    }
    printf("Element %d not found in the array (Linear Search).\n", target);
}

void binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Element %d found at index %d (Binary Search).\n", target, mid);
            return;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element %d not found in the array (Binary Search).\n", target);
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Exit\n");
}