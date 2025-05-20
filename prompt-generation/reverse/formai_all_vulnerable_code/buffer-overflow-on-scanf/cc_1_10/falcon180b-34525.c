//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int size;

void insert(int val) {
    if (size == MAX_SIZE) {
        printf("Error: Array is full\n");
        return;
    }
    arr[size++] = val;
}

void delete(int val) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == val) {
            arr[i] = arr[--size];
            return;
        }
    }
    printf("Error: Value not found in array\n");
}

void search(int val) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == val) {
            printf("Value found at index %d\n", i);
            return;
        }
    }
    printf("Value not found in array\n");
}

int main() {
    int choice, val;
    while (true) {
        printf("Enter 1 to insert a value\n");
        printf("Enter 2 to delete a value\n");
        printf("Enter 3 to search for a value\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete(val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}