//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to perform linear search
int paranoid_linear_search(char* array, int size, char* target) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(array[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int paranoid_binary_search(char* array, int size, char* target) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(array[mid], target) == 0) {
            return mid;
        } else if (strcmp(array[mid], target) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    char* array = malloc(MAX_SIZE * sizeof(char));
    int size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    while (size > 0) {
        scanf("%s", array + size * sizeof(char));
        size--;
    }

    char* target;
    printf("Enter the target element to search for: ");
    scanf("%s", target);

    int result1 = paranoid_linear_search(array, size, target);
    int result2 = paranoid_binary_search(array, size, target);

    if (result1 == -1) {
        printf("Element not found using linear search.\n");
    } else {
        printf("Element found at position %d using linear search.\n", result1);
    }

    if (result2 == -1) {
        printf("Element not found using binary search.\n");
    } else {
        printf("Element found at position %d using binary search.\n", result2);
    }

    free(array);
    return 0;
}