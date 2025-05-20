//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int option, size, target;

    printf("Welcome to the C Searching Algorithm Program!\n");
    printf("1. Input Array\n");
    printf("2. Sort Array\n");
    printf("3. Search in Array\n");
    printf("4. Exit\n");

    int *array = NULL;

    do {
        printf("\nPlease select an option (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                array = (int *)malloc(size * sizeof(int));
                printf("Enter %d integers:\n", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &array[i]);
                }
                printArray(array, size);
                break;

            case 2:
                if (array != NULL) {
                    sortArray(array, size);
                    printf("Array sorted!\n");
                    printArray(array, size);
                } else {
                    printf("Please input the array first (Option 1).\n");
                }
                break;

            case 3:
                if (array != NULL) {
                    printf("Enter the integer to search for: ");
                    scanf("%d", &target);
                    int index = binarySearch(array, size, target);
                    if (index != -1) {
                        printf("Element %d found at index %d.\n", target, index);
                    } else {
                        printf("Element %d not found in the array.\n", target);
                    }
                } else {
                    printf("Please input the array first (Option 1).\n");
                }
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                free(array);
                break;

            default:
                printf("Invalid option. Please choose again.\n");
        }
    } while (option != 4);

    return 0;
}