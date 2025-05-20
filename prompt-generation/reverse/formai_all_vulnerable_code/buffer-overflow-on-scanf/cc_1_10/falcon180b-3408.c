//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

Node arr[MAX_SIZE];
int size = 0;

void insert(int data) {
    if (size == MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    arr[size].data = data;
    arr[size].index = size;
    size++;
}

void delete(int data) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i].data == data) {
            arr[i].data = arr[size - 1].data;
            arr[i].index = arr[size - 1].index;
            arr[size - 1].data = -1;
            arr[size - 1].index = -1;
            size--;
            return;
        }
    }
    printf("Element not found\n");
}

void search(int data) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i].data == data) {
            printf("Element found at index %d\n", arr[i].index);
            return;
        }
    }
    printf("Element not found\n");
}

void display() {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            delete(data);
            break;
        case 3:
            printf("Enter data to search: ");
            scanf("%d", &data);
            search(data);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}