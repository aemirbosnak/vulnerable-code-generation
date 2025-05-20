//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int* allocateMemory(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        handleError("Allocation failed");
    }
    return arr;
}

void freeMemory(int *arr) {
    free(arr);
}

void inputIntegers(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            while(getchar() != '\n'); // Clear invalid input
            handleError("Invalid input, please enter an integer");
        }
    }
}

void displayIntegers(int *arr, int size) {
    printf("The integers are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int searchInteger(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Found
        }
    }
    return -1; // Not found
}

int main() {
    int size;

    printf("Enter the number of integers you want to store: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        handleError("Invalid size input");
    }

    int *arr = allocateMemory(size);
    inputIntegers(arr, size);
    displayIntegers(arr, size);

    int target;
    printf("Enter an integer to search: ");
    if (scanf("%d", &target) != 1) {
        while(getchar() != '\n'); // Clear invalid input
        handleError("Invalid input for search");
    }

    int index = searchInteger(arr, size, target);
    if (index != -1) {
        printf("Integer %d found at index: %d\n", target, index);
    } else {
        printf("Integer %d not found in the array.\n", target);
    }

    freeMemory(arr);
    return 0;
}