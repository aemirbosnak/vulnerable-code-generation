//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createArray() {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
    arr->data = (int *)malloc(arr->capacity * sizeof(int));
    return arr;
}

void freeArray(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

void resizeArray(DynamicArray *arr) {
    arr->capacity *= 2;
    arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
}

void addElement(DynamicArray *arr, int element) {
    if (arr->size >= arr->capacity) {
        resizeArray(arr);
    }
    arr->data[arr->size++] = element;
}

void removeElement(DynamicArray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Index %d is out of bounds.\n", index);
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void displayArray(DynamicArray *arr) {
    if (arr->size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Dynamic Array: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *dynamicArray = createArray();
    int choice, element, index;

    do {
        printf("\nDynamic Array Menu:\n");
        printf("1. Add Element\n");
        printf("2. Remove Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                addElement(dynamicArray, element);
                break;
            case 2:
                printf("Enter index of element to remove: ");
                scanf("%d", &index);
                removeElement(dynamicArray, index);
                break;
            case 3:
                displayArray(dynamicArray);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
                break;
        }
    } while (choice != 4);

    freeArray(dynamicArray);
    return 0;
}