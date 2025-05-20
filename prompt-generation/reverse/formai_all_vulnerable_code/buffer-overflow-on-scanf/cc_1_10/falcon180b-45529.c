//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int size;
} Array;

Array* create_array() {
    Array* a = (Array*) malloc(sizeof(Array));
    if (a == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    a->size = 0;
    return a;
}

void insert_array(Array* a, int value) {
    if (a->size >= MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    a->data[a->size] = value;
    a->size++;
}

bool search_array(Array* a, int value) {
    int i;
    for (i = 0; i < a->size; i++) {
        if (a->data[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    Array* a = create_array();
    int n, value, found = 0, pos = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a->data[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &value);

    if (search_array(a, value)) {
        printf("Element found at position %d\n", pos);
        found = 1;
    } else {
        printf("Element not found\n");
    }

    if (!found) {
        printf("Do you want to insert the element? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            printf("Enter the position to insert the element: ");
            scanf("%d", &pos);
            insert_array(a, value);
            printf("Element inserted at position %d\n", pos);
        }
    }

    return 0;
}