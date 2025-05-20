//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY_SIZE 100

void print_array(int arr[], int size, const char* name) {
    printf("%s unsorted array:\n", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int size) {
    int swapped;
    for (int j = 0; j < size - 1; j++) {
        swapped = 0;
        for (int i = 0; i < size - j - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void selection_sort(int arr[], int size) {
    int min_idx;
    for (int i = 0; i < size - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int size, choice, sort_choice;

    printf("Enter array size: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    print_array(arr, size, "Before sorting");

    printf("\nChoose sorting algorithm (1 for bubble sort, 2 for selection sort): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubble_sort(arr, size);
            break;
        case 2:
            selection_sort(arr, size);
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            return 1;
    }

    print_array(arr, size, "After sorting");

    return 0;
}