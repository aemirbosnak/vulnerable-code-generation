//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: realistic
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

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse* warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse* warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Cannot add more items, warehouse is full.\n");
        return;
    }
    
    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse* warehouse) {
    int id, found = 0;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            found = 1;
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item removed successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Item with ID %d not found.\n", id);
    }
}

void displayItems(const Warehouse* warehouse) {
    if (warehouse->count == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    
    printf("%-10s %-20s %-10s\n", "ID", "Name", "Quantity");
    printf("=====================================\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%-10d %-20s %-10d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void menu() {
    printf("\n=== Warehouse Management System ===\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Items\n");
    printf("4. Exit\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    do {
        menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                displayItems(&warehouse);
                break;
            case 4:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}