//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int total_items = 0;

void addItem() {
    if (total_items >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = total_items + 1; // Simple ID assignment
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    warehouse[total_items] = newItem;
    total_items++;
    printf("Item added: ID:%d Name:%s Quantity:%d\n", newItem.id, newItem.name, newItem.quantity);
}

void listItems() {
    if (total_items == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("Current items in warehouse:\n");
    printf("ID\tName\tQuantity\n");
    for (int i = 0; i < total_items; i++) {
        printf("%d\t%s\t%d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

void updateItem() {
    int id;
    printf("Enter the item ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > total_items) {
        printf("Invalid item ID.\n");
        return;
    }

    printf("Current quantity for %s is %d\n", warehouse[id - 1].name, warehouse[id - 1].quantity);
    printf("Enter new quantity: ");
    scanf("%d", &warehouse[id - 1].quantity);
    printf("Item updated: %s now has %d units.\n", warehouse[id - 1].name, warehouse[id - 1].quantity);
}

void deleteItem() {
    int id;
    printf("Enter the item ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > total_items) {
        printf("Invalid item ID.\n");
        return;
    }

    for (int i = id - 1; i < total_items - 1; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    total_items--;
    printf("Item deleted.\n");
}

void showMenu() {
    printf("\n*** Warehouse Management System ***\n");
    printf("1. Add Item\n");
    printf("2. List Items\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int option;

    while (1) {
        showMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }

    return 0;
}