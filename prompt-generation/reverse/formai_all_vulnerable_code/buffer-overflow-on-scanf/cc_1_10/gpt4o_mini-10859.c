//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

// Struct for an item in the warehouse
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Item;

// Global variables
Item warehouse[MAX_ITEMS];
int itemCount = 0;

// Function to add an item to the warehouse
void addItem(int id, const char *name, int quantity) {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse limit reached. Cannot add more items.\n");
        return;
    }
    warehouse[itemCount].id = id;
    strncpy(warehouse[itemCount].name, name, NAME_LENGTH);
    warehouse[itemCount].quantity = quantity;
    itemCount++;
    printf("Item added: %s (ID: %d, Quantity: %d)\n", name, id, quantity);
}

// Function to view all items in the warehouse
void viewItems() {
    if (itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("Warehouse Inventory:\n");
    printf("%-5s %-30s %s\n", "ID", "Name", "Quantity");
    for (int i = 0; i < itemCount; i++) {
        printf("%-5d %-30s %d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

// Function to delete an item from the warehouse
void deleteItem(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            // Shift items to fill the gap
            for (int j = i; j < itemCount - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            itemCount--;
            printf("Item with ID %d has been deleted.\n", id);
            return;
        }
    }
    printf("Item with ID %d not found in the warehouse.\n", id);
}

// Function to display the menu options
void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. View Items\n");
    printf("3. Delete Item\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int id, quantity;
                char name[NAME_LENGTH];
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                addItem(id, name, quantity);
                break;
            }
            case 2:
                viewItems();
                break;
            case 3: {
                int id;
                printf("Enter item ID to delete: ");
                scanf("%d", &id);
                deleteItem(id);
                break;
            }
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}