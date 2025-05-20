//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} InventoryItem;

typedef struct {
    InventoryItem items[MAX_ITEMS];
    int count;
} Warehouse;

void initWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void displayInventory(const Warehouse *warehouse) {
    printf("\nInventory List:\n");
    printf("ID\tName\t\tQuantity\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%d\t%s\t\t%d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    InventoryItem newItem;
    newItem.id = warehouse->count + 1; // Simple ID assignment
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to remove: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > warehouse->count) {
        printf("Invalid item ID!\n");
        return;
    }

    for (int i = id - 1; i < warehouse->count - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->count--;
    printf("Item removed successfully!\n");
}

void updateItem(Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > warehouse->count) {
        printf("Invalid item ID!\n");
        return;
    }
    
    printf("Updating Item %d\n", id);
    printf("Enter new name (old: %s): ", warehouse->items[id - 1].name);
    scanf("%s", warehouse->items[id - 1].name);
    printf("Enter new quantity (old: %d): ", warehouse->items[id - 1].quantity);
    scanf("%d", &warehouse->items[id - 1].quantity);
    
    printf("Item updated successfully!\n");
}

void searchItem(const Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to search: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > warehouse->count) {
        printf("Item not found!\n");
        return;
    }

    printf("Item Details:\n");
    printf("ID: %d\n", warehouse->items[id - 1].id);
    printf("Name: %s\n", warehouse->items[id - 1].name);
    printf("Quantity: %d\n", warehouse->items[id - 1].quantity);
}

void menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item\n");
    printf("4. Search Item\n");
    printf("5. Display Inventory\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse);

    int option;
    while (1) {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                updateItem(&warehouse);
                break;
            case 4:
                searchItem(&warehouse);
                break;
            case 5:
                displayInventory(&warehouse);
                break;
            case 6:
                printf("Exiting Warehouse Management System.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}