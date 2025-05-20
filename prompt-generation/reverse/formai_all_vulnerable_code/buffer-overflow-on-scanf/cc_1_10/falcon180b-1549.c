//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Node;

void insert(Node *arr, int val) {
    int i = 0;
    while (i < MAX_SIZE && arr[i].data!= val) {
        i++;
    }
    if (i == MAX_SIZE) {
        printf("Error: Cannot insert value %d, array is full.\n", val);
        return;
    }
    arr[i].data = val;
    arr[i].index = i;
}

void delete(Node *arr, int val) {
    int i = 0;
    while (i < MAX_SIZE && arr[i].data!= val) {
        i++;
    }
    if (i == MAX_SIZE) {
        printf("Error: Cannot delete value %d, not found in array.\n", val);
        return;
    }
    arr[i].data = 0;
    arr[i].index = 0;
}

void search(Node *arr, int val) {
    int i = 0;
    while (i < MAX_SIZE && arr[i].data!= val) {
        i++;
    }
    if (i == MAX_SIZE) {
        printf("Error: Cannot search for value %d, not found in array.\n", val);
        return;
    }
    printf("Value %d found at index %d.\n", val, arr[i].index);
}

int main() {
    Node arr[MAX_SIZE];
    int choice, val;

    do {
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(arr, val);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            delete(arr, val);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(arr, val);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}