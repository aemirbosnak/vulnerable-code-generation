//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    char name[20];
} Record;

void swap(Record *a, Record *b) {
    Record temp = *a;
    *a = *b;
    *b = temp;
}

int binary_search(Record arr[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m].key == key) {
            return m;
        } else if (arr[m].key < key) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int linear_search(Record arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i].key == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    Record data[MAX_SIZE];
    int n, choice, index, key;

    printf("Enter number of records: ");
    scanf("%d", &n);

    printf("Enter records:\n");
    for (int i = 0; i < n; i++) {
        printf("Record %d:\n", i + 1);
        printf("Key: ");
        scanf("%d", &data[i].key);
        printf("Name: ");
        scanf("%s", data[i].name);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Binary Search\n");
        printf("2. Linear Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = binary_search(data, 0, n - 1, key);
                if (index == -1) {
                    printf("Key not found!\n");
                } else {
                    printf("Key %d found at position %d.\n", key, index + 1);
                }
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = linear_search(data, n, key);
                if (index == -1) {
                    printf("Key not found!\n");
                } else {
                    printf("Key %d found at position %d.\n", key, index + 1);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}