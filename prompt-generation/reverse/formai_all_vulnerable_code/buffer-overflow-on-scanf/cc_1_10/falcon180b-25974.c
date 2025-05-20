//Falcon-180B DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void display_menu() {
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Display items\n");
    printf("4. Exit\n");
}

void add_item(char *items[], int size) {
    char item[MAX_SIZE];
    printf("Enter item to add: ");
    scanf("%s", item);
    items[size] = strdup(item);
    size++;
    items[size] = NULL;
}

void remove_item(char *items[], int size) {
    printf("Enter item to remove: ");
    char item[MAX_SIZE];
    scanf("%s", item);
    int i = 0;
    while (items[i]!= NULL && strcmp(items[i], item)!= 0) {
        i++;
    }
    if (items[i]!= NULL) {
        free(items[i]);
        items[i] = NULL;
    }
}

void display_items(char *items[], int size) {
    printf("Items:\n");
    for (int i = 0; items[i]!= NULL; i++) {
        printf("%s\n", items[i]);
    }
}

int main() {
    char *items[MAX_SIZE];
    int size = 0;

    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(items, size);
                break;
            case 2:
                remove_item(items, size);
                break;
            case 3:
                display_items(items, size);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}