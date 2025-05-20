//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void linearSearch(int arr[], int size, int target);
void binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);
int compare(const void *a, const void *b);

int main() {
    int choice, target, size;

    printf("Welcome to the Search Algorithm Program!\n");
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 3) {
            break; // Exit
        }

        printf("Enter the number to search for: ");
        scanf("%d", &target);

        switch (choice) {
            case 1:
                linearSearch(arr, size, target);
                break;
            case 2:
                sortArray(arr, size);
                binarySearch(arr, size, target);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    free(arr);
    printf("Thank you for using the program!\n");
    return 0;
}

void displayMenu() {
    printf("\nChoose a search algorithm:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (requires sorted array)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void linearSearch(int arr[], int size, int target) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Found %d at index %d using Linear Search.\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%d not found in the array using Linear Search.\n", target);
    }
}

void binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int found = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            printf("Found %d at index %d using Binary Search.\n", target, mid);
            found = 1;
            break;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("%d not found in the array using Binary Search.\n", target);
    }
}

void sortArray(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}