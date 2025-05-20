//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int arr[MAX];
int n;

void create(int size) {
    int i;
    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    n = size;
}

void display() {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search(int key) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d found at position %d\n", key, i);
            return;
        }
    }
    printf("%d not found\n", key);
}

int main() {
    int choice, size;

    while (1) {
        printf("1. Enter elements\n2. Display elements\n3. Search element\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the size of the array: ");
            scanf("%d", &size);
            create(size);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the element to search: ");
            int key;
            scanf("%d", &key);
            search(key);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}