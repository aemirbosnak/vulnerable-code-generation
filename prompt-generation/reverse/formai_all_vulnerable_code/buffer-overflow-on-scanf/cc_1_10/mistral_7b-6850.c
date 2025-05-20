//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define KEY_SIZE 20

typedef struct {
    int key;
    char value[MAX_SIZE];
} Data;

void print_menu();
void search(Data arr[], int size, int key);
void insert(Data arr[], int *size, int key, char value[]);

int main() {
    Data arr[MAX_SIZE];
    int size = 0;
    int choice, key, i;
    char value[MAX_SIZE];

    print_menu();

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size == MAX_SIZE) {
                    printf("Array is full.\n");
                    break;
                }

                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%s", value);

                insert(arr, &size, key, value);
                printf("Inserted %d with value \"%s\"\n", key, value);
                break;

            case 2:
                if (size == 0) {
                    printf("Array is empty.\n");
                    break;
                }

                printf("Enter key to search: ");
                scanf("%d", &key);

                search(arr, size, key);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

        print_menu();
    }

    return 0;
}

void print_menu() {
    printf("\n1. Insert data\n");
    printf("2. Search data\n");
    printf("3. Exit\n");
}

void search(Data arr[], int size, int key) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i].key == key) {
            printf("Key %d found at position %d with value \"%s\"\n", key, i + 1, arr[i].value);
            return;
        }
    }

    printf("Key %d not found.\n", key);
}

void insert(Data arr[], int *size, int key, char value[]) {
    if (*size == MAX_SIZE) {
        return;
    }

    arr[*size].key = key;
    strcpy(arr[*size].value, value);
    (*size)++;
}