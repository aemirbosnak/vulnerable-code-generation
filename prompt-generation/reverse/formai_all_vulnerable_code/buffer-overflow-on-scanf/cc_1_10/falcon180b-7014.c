//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int key;
} Node;

Node arr[MAX_SIZE];
int n = 0;

void insert(int value, int key) {
    if (n >= MAX_SIZE) {
        printf("Array is full!\n");
        return;
    }

    Node newNode = {value, key};
    arr[n++] = newNode;
}

void search(int key) {
    int i = 0;
    while (i < n) {
        if (arr[i].key == key) {
            printf("Element found at index %d\n", i);
            return;
        }
        i++;
    }
    printf("Element not found\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and key:\n");
                scanf("%d %d", &value, &key);
                insert(value, key);
                break;
            case 2:
                printf("Enter key to search:\n");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}