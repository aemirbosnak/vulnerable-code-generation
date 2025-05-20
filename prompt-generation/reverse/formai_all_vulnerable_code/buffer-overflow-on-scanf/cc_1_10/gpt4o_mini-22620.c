//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse->items[warehouse->itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void viewItems(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("\nItems in Warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", 
            warehouse->items[i].id, 
            warehouse->items[i].name, 
            warehouse->items[i].quantity);
    }
}

void removeItem(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse to remove.\n");
        return;
    }
    
    int id;
    printf("Enter the ID of the item to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i] = warehouse->items[warehouse->itemCount - 1];
            warehouse->itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void searchItem(Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            printf("Item found: ID: %d, Name: %s, Quantity: %d\n", 
                warehouse->items[i].id, 
                warehouse->items[i].name, 
                warehouse->items[i].quantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void updateItem(Warehouse *warehouse) {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            printf("Current Name: %s, Current Quantity: %d\n", 
                warehouse->items[i].name, 
                warehouse->items[i].quantity);
            printf("Enter new name: ");
            scanf("%s", warehouse->items[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &warehouse->items[i].quantity);
            printf("Item updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Remove Item\n");
    printf("4. Search Item\n");
    printf("5. Update Item\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                viewItems(&warehouse);
                break;
            case 3:
                removeItem(&warehouse);
                break;
            case 4:
                searchItem(&warehouse);
                break;
            case 5:
                updateItem(&warehouse);
                break;
            case 6:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}