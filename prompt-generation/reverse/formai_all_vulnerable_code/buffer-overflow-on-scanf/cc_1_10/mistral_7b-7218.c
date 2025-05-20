//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int nextItemIndex = 0;

void printMenu() {
    printf("Warehouse Management System\n");
    printf("---------------------------\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Search item\n");
    printf("4. Display warehouse\n");
    printf("5. Exit\n");
}

void addItem() {
    if (nextItemIndex >= MAX_ITEMS) {
        printf("Warehouse is full.\n");
        return;
    }
    printf("Enter item name: ");
    scanf("%s", warehouse[nextItemIndex].name);
    printf("Enter item quantity: ");
    scanf("%d", &warehouse[nextItemIndex].quantity);
    nextItemIndex++;
}

void removeItem() {
    char name[MAX_NAME_LEN];
    int index = -1;
    printf("Enter item name to remove: ");
    scanf("%s", name);
    for (int i = 0; i < nextItemIndex; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Item not found.\n");
        return;
    }
    for (int i = index; i < nextItemIndex - 1; i++) {
        warehouse[i] = warehouse[i+1];
    }
    nextItemIndex--;
}

void searchItem() {
    char name[MAX_NAME_LEN];
    int quantity = 0;
    int found = 0;
    printf("Enter item name to search: ");
    scanf("%s", name);
    for (int i = 0; i < nextItemIndex; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            found = 1;
            quantity = warehouse[i].quantity;
            break;
        }
    }
    if (found) {
        printf("Item %s found with quantity %d.\n", name, quantity);
    } else {
        printf("Item not found.\n");
    }
}

void displayWarehouse() {
    printf("Warehouse contents:\n");
    for (int i = 0; i < nextItemIndex; i++) {
        printf("%s: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    while (1) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                searchItem();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                displayWarehouse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}