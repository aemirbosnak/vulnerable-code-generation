//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int size;

void insert(int val) {
    if (size == MAX_SIZE) {
        printf("Array is full.\n");
        return;
    }
    arr[size++] = val;
}

void delete(int index) {
    if (index >= size || index < 0) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void search(int val) {
    int index = 0;
    while (index < size && arr[index]!= val) {
        index++;
    }
    if (index == size) {
        printf("Value not found.\n");
    } else {
        printf("Value found at index %d.\n", index);
    }
}

int main() {
    int choice, val;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        insert(i);
    }

    do {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            printf("Enter the index to delete: ");
            scanf("%d", &val);
            delete(val);
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d", &val);
            search(val);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice!= 4);

    return 0;
}