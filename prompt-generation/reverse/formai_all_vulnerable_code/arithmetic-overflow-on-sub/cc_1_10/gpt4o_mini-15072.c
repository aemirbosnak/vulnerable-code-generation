//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
int linearSearch(int arr[], int n, int x);
int binarySearch(int arr[], int left, int right, int x);
void printArray(int arr[], int n);
void sortArray(int arr[], int n);
void generateRandomArray(int arr[], int n, int range);
void displayMenu();
void handleUserInput(int option, int *arr, int n);

int main() {
    int n, option;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    generateRandomArray(arr, n, 100); // Generate random elements in the range from 0 to 99
    printf("Generated array:\n");
    printArray(arr, n);

    do {
        displayMenu();
        printf("Choose an option (1-3): ");
        scanf("%d", &option);
        if (option < 1 || option > 3) {
            printf("Invalid option, please try again.\n");
            continue;
        }
        handleUserInput(option, arr, n);
    } while (option != 3);

    free(arr);
    return EXIT_SUCCESS;
}

void generateRandomArray(int arr[], int n, int range) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  // Return index if found
        }
    }
    return -1;  // Not found
}

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;  // Return index if found
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Not found
}

void displayMenu() {
    printf("\n--- Search Algorithm Menu ---\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array must be sorted)\n");
    printf("3. Exit\n");
}

void handleUserInput(int option, int *arr, int n) {
    int x, result;
    switch (option) {
        case 1:
            printf("Enter the element to search (Linear Search): ");
            scanf("%d", &x);
            result = linearSearch(arr, n, x);
            if (result != -1) {
                printf("Element found at index: %d\n", result);
            } else {
                printf("Element not found.\n");
            }
            break;
        case 2:
            sortArray(arr, n);
            printf("Sorted array for Binary Search:\n");
            printArray(arr, n);
            printf("Enter the element to search (Binary Search): ");
            scanf("%d", &x);
            result = binarySearch(arr, 0, n - 1, x);
            if (result != -1) {
                printf("Element found at index: %d\n", result);
            } else {
                printf("Element not found.\n");
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
    }
}