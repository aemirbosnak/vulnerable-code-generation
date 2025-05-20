//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

// Structure to represent an item in the warehouse
typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

// Warehouse structure to hold items
typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

// Function to initialize the warehouse
void initializeWarehouse(Warehouse* warehouse) {
    warehouse->count = 0;
}

// Function to add an item to the warehouse
void addItem(Warehouse* warehouse, const char* name, int quantity) {
    if (warehouse->count < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->count].name, name);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->count++;
        printf("Added item: %s with quantity: %d\n", name, quantity);
    } else {
        printf("Warehouse is full! Cannot add new item: %s\n", name);
    }
}

// Function to view all items in the warehouse
void viewItems(Warehouse* warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("Items in Warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item Name: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

// Function to delete an item from the warehouse
void deleteItem(Warehouse* warehouse, const char* name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1]; // Shift items left
            }
            warehouse->count--;
            printf("Deleted item: %s\n", name);
            return;
        }
    }
    printf("Item not found: %s\n", name);
}

// Main function to run the warehouse management system
int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Delete Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Handle user choices
        if (choice == 1) {
            char name[ITEM_NAME_LENGTH];
            int quantity;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            addItem(&warehouse, name, quantity);
        } else if (choice == 2) {
            viewItems(&warehouse);
        } else if (choice == 3) {
            char name[ITEM_NAME_LENGTH];
            printf("Enter item name to delete: ");
            scanf("%s", name);
            deleteItem(&warehouse, name);
        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}