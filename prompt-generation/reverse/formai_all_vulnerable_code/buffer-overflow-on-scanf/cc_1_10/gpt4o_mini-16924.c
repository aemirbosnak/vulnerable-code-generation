//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: decentralized
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

// Function prototypes
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void listItems(Warehouse *warehouse);
void runWarehouseSystem(Warehouse *warehouse);

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    runWarehouseSystem(&warehouse);
    return 0;
}

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    printf("Item added successfully.\n");
}

void removeItem(Warehouse *warehouse) {
    char itemName[ITEM_NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", itemName);

    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, itemName) == 0) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Item removed successfully.\n");
            return;
        }
    }

    printf("Item not found!\n");
}

void listItems(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }

    printf("\nList of items in warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Item Name: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void runWarehouseSystem(Warehouse *warehouse) {
    int choice;

    do {
        printf("\nWarehouse Management System Menu:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. List Items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(warehouse);
                break;
            case 2:
                removeItem(warehouse);
                break;
            case 3:
                listItems(warehouse);
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}