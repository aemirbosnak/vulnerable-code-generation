//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size;

void insert(int value) {
    if (size == MAX_SIZE) {
        printf("Error: Array is full!\n");
        return;
    }
    arr[size++] = value;
}

void delete(int value) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == value) {
            size--;
            for (int j = i; j < size; j++) {
                arr[j] = arr[j + 1];
            }
            return;
        }
    }
    printf("Error: Value not found!\n");
}

void search(int value) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Value found at index %d!\n", i);
            return;
        }
    }
    printf("Error: Value not found!\n");
}

void print() {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Artistic Searching Algorithm!\n\n");
    size = 0;
    while (true) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            int value;
            scanf("%d", &value);
            insert(value);
            printf("Value inserted successfully!\n");
            break;
        case 2:
            printf("Enter the value to delete: ");
            int valueToDelete;
            scanf("%d", &valueToDelete);
            delete(valueToDelete);
            printf("Value deleted successfully!\n");
            break;
        case 3:
            printf("Enter the value to search: ");
            int valueToSearch;
            scanf("%d", &valueToSearch);
            search(valueToSearch);
            break;
        case 4:
            print();
            break;
        case 0:
            exit(0);
        default:
            printf("Error: Invalid choice!\n");
        }
    }
    return 0;
}