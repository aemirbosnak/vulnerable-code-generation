//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void resizeDynamicArray(DynamicArray *array) {
    array->capacity *= 2;
    array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
}

void addElementToDynamicArray(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array);
    }
    array->data[array->size++] = element;
}

int main() {
    DynamicArray *array = createDynamicArray();
    int choice, element;

    do {
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Display elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &element);
                addElementToDynamicArray(array, element);
                break;
            case 2:
                printf("Enter the element to remove: ");
                scanf("%d", &element);
                int index = -1;
                for (int i = 0; i < array->size; i++) {
                    if (array->data[i] == element) {
                        index = i;
                        break;
                    }
                }
                if (index!= -1) {
                    for (int i = index; i < array->size - 1; i++) {
                        array->data[i] = array->data[i + 1];
                    }
                    array->size--;
                } else {
                    printf("Element not found\n");
                }
                break;
            case 3:
                printf("Current elements in the array:\n");
                for (int i = 0; i < array->size; i++) {
                    printf("%d ", array->data[i]);
                }
                printf("\n");
                break;
            case 4:
                destroyDynamicArray(array);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}