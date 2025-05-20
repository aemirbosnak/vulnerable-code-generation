//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void inputArray(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void menu() {
    printf("Menu:\n");
    printf("1. Input Array\n");
    printf("2. Sort Array\n");
    printf("3. Display Array\n");
    printf("4. Exit\n");
}

int main() {
    int size = 0;
    int *arr = NULL;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size of array: ");
                scanf("%d", &size);
                arr = (int *)malloc(size * sizeof(int));
                if (arr == NULL) {
                    printf("Memory allocation failed\n");
                    exit(EXIT_FAILURE);
                }
                inputArray(arr, size);
                break;

            case 2:
                if (arr != NULL && size > 0) {
                    quickSort(arr, 0, size - 1);
                    printf("Array sorted successfully!\n");
                } else {
                    printf("You need to input the array first!\n");
                }
                break;

            case 3:
                if (arr != NULL && size > 0) {
                    printf("The sorted array is:\n");
                    displayArray(arr, size);
                } else {
                    printf("You need to input the array first!\n");
                }
                break;

            case 4:
                free(arr);
                printf("Exiting the program...\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}