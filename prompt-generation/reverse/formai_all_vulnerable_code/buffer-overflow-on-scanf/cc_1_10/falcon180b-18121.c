//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

void createArray(Array *array) {
    array->data = (int*)malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
}

void insertElement(Array *array, int element) {
    if (array->size == MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    array->data[array->size++] = element;
}

int binarySearch(Array array, int target) {
    int left = 0;
    int right = array.size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array.data[mid] == target) {
            return mid;
        } else if (array.data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    Array array;
    createArray(&array);

    int choice, element;

    do {
        printf("Enter your choice:\n");
        printf("1. Insert element\n");
        printf("2. Binary search\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert:\n");
                scanf("%d", &element);
                insertElement(&array, element);
                break;
            case 2:
                printf("Enter target element for binary search:\n");
                scanf("%d", &element);
                int result = binarySearch(array, element);

                if (result == -1) {
                    printf("Element not found.\n");
                } else {
                    printf("Element found at index %d.\n", result);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}