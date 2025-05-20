//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSES 5
#define MAX_ITEMS 50
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    char name[NAME_LENGTH];
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

Warehouse warehouses[MAX_WAREHOUSES];
int warehouseCount = 0;

void addWarehouse() {
    if (warehouseCount >= MAX_WAREHOUSES) {
        printf("Error: Maximum number of warehouses reached.\n");
        return;
    }
    
    Warehouse newWarehouse;
    printf("Enter warehouse name: ");
    scanf(" %[^\n]", newWarehouse.name);
    newWarehouse.itemCount = 0;
    warehouses[warehouseCount++] = newWarehouse;
    printf("Warehouse '%s' added successfully!\n", newWarehouse.name);
}

void addItem() {
    char warehouseName[NAME_LENGTH];
    printf("Enter warehouse name to add item: ");
    scanf(" %[^\n]", warehouseName);
    
    Warehouse *warehouse = NULL;
    for (int i = 0; i < warehouseCount; i++) {
        if (strcmp(warehouses[i].name, warehouseName) == 0) {
            warehouse = &warehouses[i];
            break;
        }
    }
    
    if (!warehouse) {
        printf("Error: Warehouse not found.\n");
        return;
    }
    
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached in warehouse '%s'.\n", warehouse->name);
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse->items[warehouse->itemCount++] = newItem;
    printf("Item '%s' added to warehouse '%s' successfully!\n", newItem.name, warehouse->name);
}

void listItems() {
    char warehouseName[NAME_LENGTH];
    printf("Enter warehouse name to list items: ");
    scanf(" %[^\n]", warehouseName);
    
    Warehouse *warehouse = NULL;
    for (int i = 0; i < warehouseCount; i++) {
        if (strcmp(warehouses[i].name, warehouseName) == 0) {
            warehouse = &warehouses[i];
            break;
        }
    }
    
    if (!warehouse) {
        printf("Error: Warehouse not found.\n");
        return;
    }
    
    printf("Items in warehouse '%s':\n", warehouse->name);
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("- %s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void removeItem() {
    char warehouseName[NAME_LENGTH];
    printf("Enter warehouse name to remove item from: ");
    scanf(" %[^\n]", warehouseName);
    
    Warehouse *warehouse = NULL;
    for (int i = 0; i < warehouseCount; i++) {
        if (strcmp(warehouses[i].name, warehouseName) == 0) {
            warehouse = &warehouses[i];
            break;
        }
    }
    
    if (!warehouse) {
        printf("Error: Warehouse not found.\n");
        return;
    }

    char itemName[NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf(" %[^\n]", itemName);
    
    int found = 0;
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, itemName) == 0) {
            found = 1;
            printf("Removing item '%s' from warehouse '%s'.\n", warehouse->items[i].name, warehouse->name);
            // Shift items to fill the gap
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            break;
        }
    }
    
    if (!found) {
        printf("Error: Item '%s' not found in warehouse '%s'.\n", itemName, warehouse->name);
    }
}

void displayMenu() {
    printf("\n--- Warehouse Management System ---\n");
    printf("1. Add Warehouse\n");
    printf("2. Add Item\n");
    printf("3. List Items\n");
    printf("4. Remove Item\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWarehouse();
                break;
            case 2:
                addItem();
                break;
            case 3:
                listItems();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}