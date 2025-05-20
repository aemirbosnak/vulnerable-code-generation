//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

Element arr[MAX_SIZE];
int size = 0;

void insert(int data) {
    if (size == MAX_SIZE) {
        printf("Error: Array is Full!\n");
        exit(0);
    }
    arr[size].data = data;
    arr[size].index = size;
    size++;
}

void search(int data) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i].data == data) {
            printf("%d found at index %d\n", data, arr[i].index);
            return;
        }
    }
    printf("%d not found in the array\n", data);
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            search(data);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}