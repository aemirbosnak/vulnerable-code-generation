//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define ELEMENT_NOT_FOUND -1

void print_menu();
int* create_array(int size);
void display_array(int* arr, int size);
int binary_search(int* arr, int size, int target);
int linear_search(int* arr, int size, int target);
int main() {
    int *array, choice, size, search_target;

    print_menu();
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the size of the array: ");
        scanf("%d", &size);

        if (size > MAX_SIZE) {
            printf("Array size exceeds the limit.\n");
            return 1;
        }

        array = create_array(size);

        printf("Enter %d integers:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &array[i]);
        }

        display_array(array, size);
        printf("\nEnter the number you want to search: ");
        scanf("%d", &search_target);

        int result = linear_search(array, size, search_target);
        if (result == ELEMENT_NOT_FOUND) {
            printf("Element not found.\n");
        } else {
            printf("Element found at index %d.\n", result);
        }

        free(array);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

void print_menu() {
    printf("\n1. Create and search an array\n");
    printf("0. Exit\n");
}

int* create_array(int size) {
    int *arr = (int*) malloc(size * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}

void display_array(int* arr, int size) {
    printf("\nArray elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binary_search(int* arr, int size, int target) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ELEMENT_NOT_FOUND;
}

int linear_search(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return ELEMENT_NOT_FOUND;
}