//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_LENGTH 50

// Define a struct for warehouse items
typedef struct {
    char name[MAX_LENGTH];
    int quantity;
    float price;
} WarehouseItem;

// Declare global variables
WarehouseItem inventory[MAX_ITEMS];
int itemCount = 0;

// Declare function prototypes
void addItem();
void removeItem();
void viewInventory();
void updatePrice();

// Main function
int main() {
    bool running = true;
    char choice;

    // Main menu loop
    while (running) {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n2. Remove item\n3. View inventory\n4. Update item price\n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addItem();
                break;
            case '2':
                removeItem();
                break;
            case '3':
                viewInventory();
                break;
            case '4':
                updatePrice();
                break;
            case '5':
                running = false;
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add an item to the inventory
void addItem() {
    if (itemCount == MAX_ITEMS) {
        printf("Inventory is full. Cannot add another item.\n");
        return;
    }

    WarehouseItem newItem;

    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount] = newItem;
    itemCount++;

    printf("Item added to inventory.\n");
}

// Function to remove an item from the inventory
void removeItem() {
    if (itemCount == 0) {
        printf("Inventory is empty. Cannot remove item.\n");
        return;
    }

    char searchName[MAX_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", searchName);

    int index = -1;

    // Search for item in inventory
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found in inventory.\n");
        return;
    }

    // Shift items to left to fill in the index of the removed item
    for (int i = index; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    itemCount--;

    printf("Item removed from inventory.\n");
}

// Function to view the current inventory
void viewInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nCurrent Inventory:\n\n");

    for (int i = 0; i < itemCount; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: $%.2f\n\n", inventory[i].price);
    }
}

// Function to update the price of an item
void updatePrice() {
    if (itemCount == 0) {
        printf("Inventory is empty. Cannot update item price.\n");
        return;
    }

    char searchName[MAX_LENGTH];
    printf("Enter item name to update: ");
    scanf("%s", searchName);

    int index = -1;

    // Search for item in inventory
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found in inventory.\n");
        return;
    }

    float newPrice;
    printf("Enter new item price: ");
    scanf("%f", &newPrice);

    inventory[index].price = newPrice;

    printf("Item price updated.\n");
}