//Falcon-180B DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

void initIntArray(IntArray *arr) {
    arr->data = (int *)malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
}

void addElement(IntArray *arr, int num) {
    if (arr->size == MAX_SIZE) {
        printf("Error: Array is full!\n");
        return;
    }
    arr->data[arr->size] = num;
    arr->size++;
}

void removeElement(IntArray *arr, int index) {
    if (index >= arr->size) {
        printf("Error: Index out of bounds!\n");
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void printArray(IntArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    IntArray arr;
    initIntArray(&arr);
    int choice;
    do {
        printf("1. Add element\n2. Remove element\n3. Print array\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int num;
                printf("Enter element to add: ");
                scanf("%d", &num);
                addElement(&arr, num);
                break;
            }
            case 2: {
                int index;
                printf("Enter index to remove: ");
                scanf("%d", &index);
                removeElement(&arr, index);
                break;
            }
            case 3: {
                printArray(&arr);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while (choice!= 4);
    free(arr.data);
    return 0;
}