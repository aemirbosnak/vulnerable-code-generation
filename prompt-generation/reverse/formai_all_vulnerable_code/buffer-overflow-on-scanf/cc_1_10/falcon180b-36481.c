//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int size;
    int *array;
} Array;

void createArray(Array *arr, int size) {
    arr->data = 0;
    arr->size = size;
    arr->array = (int *) malloc(size * sizeof(int));
    if(arr->array == NULL) {
        printf("Memory error!\n");
        exit(1);
    }
}

void deleteArray(Array *arr) {
    free(arr->array);
}

void addElement(Array *arr, int element) {
    if(arr->data >= MAX_SIZE) {
        printf("Array is full!\n");
        return;
    }
    arr->array[arr->data] = element;
    arr->data++;
}

void removeElement(Array *arr, int element) {
    int i;
    for(i=0; i<arr->data; i++) {
        if(arr->array[i] == element) {
            arr->data--;
            for(int j=i; j<arr->data; j++) {
                arr->array[j] = arr->array[j+1];
            }
            return;
        }
    }
    printf("Element not found!\n");
}

void printArray(Array *arr) {
    printf("Array: ");
    for(int i=0; i<arr->data; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int choice, element;
    Array arr;
    createArray(&arr, 5);
    while(1) {
        printf("1. Add element\n2. Remove element\n3. Print array\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                addElement(&arr, element);
                printf("Element added successfully!\n");
                break;
            case 2:
                printf("Enter element to remove: ");
                scanf("%d", &element);
                removeElement(&arr, element);
                printf("Element removed successfully!\n");
                break;
            case 3:
                printArray(&arr);
                break;
            case 4:
                deleteArray(&arr);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}