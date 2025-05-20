//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Node;

Node arr[MAX_SIZE];
int size = 0;

void insert(int value) {
    if (size == MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    arr[size].data = value;
    arr[size].index = size;
    size++;
}

void searchRecursive(int value, int startIndex) {
    if (startIndex > size - 1) {
        printf("Value not found\n");
        return;
    }
    if (arr[startIndex].data == value) {
        printf("Value found at index %d\n", startIndex);
        return;
    }
    searchRecursive(value, startIndex + 1);
}

int main() {
    int choice, value;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insert(value);
            printf("Value inserted\n");
            break;
        case 2:
            printf("Enter the value to be searched: ");
            scanf("%d", &value);
            searchRecursive(value, 0);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}