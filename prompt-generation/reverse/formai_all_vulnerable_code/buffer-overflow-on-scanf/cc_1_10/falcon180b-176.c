//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000 //maximum size of array

typedef struct element {
    int value;
    int index;
} Element;

Element arr[MAX_SIZE]; //array to store elements
int size = 0; //current size of array

void insert(int value) {
    if (size == MAX_SIZE) {
        printf("Error: array is full\n");
        return;
    }
    arr[size].value = value;
    arr[size].index = size;
    size++;
}

void delete(int index) {
    if (index >= size || index < 0) {
        printf("Error: index out of bounds\n");
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i].index = i + 1;
        arr[i].value = arr[i + 1].value;
    }
    size--;
}

void search(int value) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i].value == value) {
            index = arr[i].index;
            break;
        }
    }
    if (index == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", index);
    }
}

int main() {
    int choice;
    do {
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            int value;
            printf("Enter element value: ");
            scanf("%d", &value);
            insert(value);
            break;
        }
        case 2: {
            int index;
            printf("Enter element index: ");
            scanf("%d", &index);
            delete(index);
            break;
        }
        case 3: {
            int value;
            printf("Enter element value: ");
            scanf("%d", &value);
            search(value);
            break;
        }
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}