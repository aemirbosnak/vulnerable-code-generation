//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int data;
    int key;
} Node;

void insert(Node* arr, int size, int key, int data) {
    if (size == MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    if (arr[size].key == 0) {
        arr[size].key = key;
        arr[size].data = data;
    } else {
        printf("Key already exists\n");
    }
}

void display(Node* arr, int size) {
    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d,%d]\n", arr[i].key, arr[i].data);
    }
}

void search(Node* arr, int size, int key) {
    int i = 0;
    while (i < size) {
        if (arr[i].key == key) {
            printf("Key found at index %d\n", i);
            printf("Data: %d\n", arr[i].data);
            return;
        }
        i++;
    }
    printf("Key not found\n");
}

int main() {
    Node arr[MAX_SIZE];
    int size = 0;
    int key;
    int data;
    char choice;

    do {
        printf("Enter 1 to insert a key-value pair\n");
        printf("Enter 2 to search for a key\n");
        printf("Enter 3 to display the array\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter data: ");
            scanf("%d", &data);
            insert(arr, size, key, data);
            size++;
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            search(arr, size, key);
            break;
        case 3:
            display(arr, size);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}