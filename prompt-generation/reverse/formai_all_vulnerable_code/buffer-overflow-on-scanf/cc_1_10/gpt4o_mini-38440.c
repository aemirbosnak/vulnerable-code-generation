//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int condition = ascending ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1];
            if (condition) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(int arr[], int n) {
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Welcome to the Bubble Sort Program!\n");

    do {
        printf("Please enter a positive number for the size of the array: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Invalid input! The size of the array must be a positive integer.\n");
        }
    } while (n <= 0);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        printf("Choose sorting order:\n");
        printf("1. Ascending Order\n");
        printf("2. Descending Order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(arr, n, 1);
                displayArray(arr, n);
                break;
            case 2:
                bubbleSort(arr, n, 0);
                displayArray(arr, n);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    } while (choice != 3);

    free(arr);
    return 0;
}