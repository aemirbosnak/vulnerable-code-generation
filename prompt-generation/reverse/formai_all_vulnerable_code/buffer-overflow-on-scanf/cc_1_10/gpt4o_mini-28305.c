//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->itemCount < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->itemCount].name, name);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->itemCount++;
        printf("Added %d of item '%s' to the warehouse.\n", quantity, name);
    } else {
        printf("Warehouse is full, cannot add more items!\n");
    }
}

void removeItem(Warehouse *warehouse, const char *name, int quantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (warehouse->items[i].quantity >= quantity) {
                warehouse->items[i].quantity -= quantity;
                printf("Removed %d of item '%s' from the warehouse.\n", quantity, name);
                if (warehouse->items[i].quantity == 0) {
                    printf("Item '%s' is now out of stock and removed from inventory.\n", name);
                    warehouse->itemCount--;
                    warehouse->items[i] = warehouse->items[warehouse->itemCount]; 
                }
                return;
            } else {
                printf("Not enough stock of item '%s' to remove %d. Available: %d\n", name, quantity, warehouse->items[i].quantity);
                return;
            }
        }
    }
    printf("Item '%s' not found in the warehouse inventory.\n", name);
}

void displayInventory(const Warehouse *warehouse) {
    printf("\nCurrent Inventory:\n");
    if (warehouse->itemCount == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse myWarehouse;
    initializeWarehouse(&myWarehouse);

    int choice, quantity;
    char itemName[ITEM_NAME_LENGTH];

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addItem(&myWarehouse, itemName, quantity);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                removeItem(&myWarehouse, itemName, quantity);
                break;
            case 3:
                displayInventory(&myWarehouse);
                break;
            case 4:
                printf("Exiting Warehouse Management System.\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}