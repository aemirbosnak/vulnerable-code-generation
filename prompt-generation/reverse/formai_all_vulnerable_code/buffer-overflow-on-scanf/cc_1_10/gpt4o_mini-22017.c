//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: innovative
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
    int count;
} Warehouse;

// Function Prototypes
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse, const char *name, int quantity);
void removeItem(Warehouse *warehouse, const char *name);
void displayInventory(Warehouse *warehouse);
int getItemIndex(Warehouse *warehouse, const char *name);

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    char name[ITEM_NAME_LENGTH];
    int quantity;

    while (1) {
        printf("\n=== Warehouse Management System ===\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, name, quantity);
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                removeItem(&warehouse, name);
                break;
            case 3:
                displayInventory(&warehouse);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    
    int index = getItemIndex(warehouse, name);
    if (index >= 0) {
        warehouse->items[index].quantity += quantity;
        printf("Updated %s quantity to %d.\n", name, warehouse->items[index].quantity);
    } else {
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Added %s with quantity %d.\n", name, quantity);
    }
}

void removeItem(Warehouse *warehouse, const char *name) {
    int index = getItemIndex(warehouse, name);
    
    if (index < 0) {
        printf("Item %s not found in inventory.\n", name);
        return;
    }
    
    warehouse->count--;
    for (int i = index; i < warehouse->count; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    printf("Removed item %s from inventory.\n", name);
}

void displayInventory(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int getItemIndex(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}