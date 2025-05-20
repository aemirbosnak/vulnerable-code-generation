//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

Warehouse warehouse;

void initializeWarehouse() {
    warehouse.itemCount = 0;
}

void addItem(const char *itemName, int qty) {
    if (warehouse.itemCount >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    for (int i = 0; i < warehouse.itemCount; i++) {
        if (strcmp(warehouse.items[i].name, itemName) == 0) {
            warehouse.items[i].quantity += qty;
            printf("Added %d to %s. New quantity: %d\n", qty, itemName, warehouse.items[i].quantity);
            return;
        }
    }
    strncpy(warehouse.items[warehouse.itemCount].name, itemName, MAX_NAME_LENGTH);
    warehouse.items[warehouse.itemCount].quantity = qty;
    warehouse.itemCount++;
    printf("Added new item: %s, Quantity: %d\n", itemName, qty);
}

void removeItem(const char *itemName, int qty) {
    for (int i = 0; i < warehouse.itemCount; i++) {
        if (strcmp(warehouse.items[i].name, itemName) == 0) {
            if (warehouse.items[i].quantity < qty) {
                printf("Not enough %s in warehouse. Current quantity: %d\n", itemName, warehouse.items[i].quantity);
                return;
            }
            warehouse.items[i].quantity -= qty;
            printf("Removed %d from %s. New quantity: %d\n", qty, itemName, warehouse.items[i].quantity);
            return;
        }
    }
    printf("Item %s not found in warehouse.\n", itemName);
}

void displayInventory() {
    printf("\nCurrent Inventory:\n");
    if (warehouse.itemCount == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    for (int i = 0; i < warehouse.itemCount; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse.items[i].name, warehouse.items[i].quantity);
    }
}

int main() {
    int choice;
    char itemName[MAX_NAME_LENGTH];
    int qty;

    initializeWarehouse();

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(itemName, MAX_NAME_LENGTH, stdin);
                itemName[strcspn(itemName, "\n")] = 0; // Remove newline
                printf("Enter item quantity: ");
                scanf("%d", &qty);
                addItem(itemName, qty);
                break;
            case 2:
                printf("Enter item name: ");
                fgets(itemName, MAX_NAME_LENGTH, stdin);
                itemName[strcspn(itemName, "\n")] = 0; // Remove newline
                printf("Enter quantity to remove: ");
                scanf("%d", &qty);
                removeItem(itemName, qty);
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Exiting Warehouse Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}