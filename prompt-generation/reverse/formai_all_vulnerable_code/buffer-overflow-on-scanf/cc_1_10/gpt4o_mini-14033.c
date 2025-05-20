//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse* warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse* warehouse, const char* name, int quantity) {
    if (warehouse->count < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Added Item: %s, Quantity: %d\n", name, quantity);
    } else {
        printf("Warehouse is full, cannot add more items!\n");
    }
}

void viewItems(const Warehouse* warehouse) {
    printf("\nCurrent Warehouse Inventory:\n");
    printf("-------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
    printf("-------------------------------\n");
}

void removeItem(Warehouse* warehouse, const char* name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Removed Item: %s\n", name);
            return;
        }
    }
    printf("Item %s not found in the warehouse.\n", name);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    char itemName[NAME_LENGTH];
    int itemQuantity;

    while (1) {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Remove Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter item quantity: ");
                scanf("%d", &itemQuantity);
                addItem(&warehouse, itemName, itemQuantity);
                break;
            case 2:
                viewItems(&warehouse);
                break;
            case 3:
                printf("Enter item name to remove: ");
                scanf("%s", itemName);
                removeItem(&warehouse, itemName);
                break;
            case 4:
                printf("Exiting Warehouse Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}