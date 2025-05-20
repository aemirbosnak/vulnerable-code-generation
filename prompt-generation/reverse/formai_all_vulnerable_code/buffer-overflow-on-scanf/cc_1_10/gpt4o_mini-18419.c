//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
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
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter the item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    
    printf("Item '%s' added successfully!\n", newItem.name);
}

void removeItem(Warehouse *warehouse) {
    char name[NAME_LENGTH];
    printf("Enter the item name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->itemCount - 1];
            warehouse->itemCount--;
            printf("Item '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Item '%s' not found in the warehouse.\n", name);
}

void viewItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("The warehouse is empty.\n");
        return;
    }
    
    printf("Items in warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void updateItemQuantity(Warehouse *warehouse) {
    char name[NAME_LENGTH];
    printf("Enter the item name to update quantity: ");
    scanf("%s", name);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            int newQuantity;
            printf("Enter new quantity for '%s': ", name);
            scanf("%d", &newQuantity);
            warehouse->items[i].quantity = newQuantity;
            printf("Quantity for '%s' updated to %d!\n", name, newQuantity);
            return;
        }
    }
    printf("Item '%s' not found in the warehouse.\n", name);
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Items\n");
    printf("4. Update Item Quantity\n");
    printf("5. Exit\n");
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
                removeItem(&warehouse);
                break;
            case 3:
                viewItems(&warehouse);
                break;
            case 4:
                updateItemQuantity(&warehouse);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}