//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

// Function to initialize the warehouse
void initWarehouse(Warehouse* warehouse) {
    warehouse->itemCount = 0;
}

// Function to add an item to the warehouse
void addItem(Warehouse* warehouse, int id, const char* name, int quantity, float price) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    warehouse->items[warehouse->itemCount].id = id;
    strncpy(warehouse->items[warehouse->itemCount].name, name, MAX_NAME_LENGTH);
    warehouse->items[warehouse->itemCount].quantity = quantity;
    warehouse->items[warehouse->itemCount].price = price;
    warehouse->itemCount++;
    printf("Item added: %s (ID: %d)\n", name, id);
}

// Function to remove an item from the warehouse
void removeItem(Warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            printf("Removing item: %s (ID: %d)\n", warehouse->items[i].name, id);
            warehouse->items[i] = warehouse->items[warehouse->itemCount - 1];
            warehouse->itemCount--;
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

// Function to update the quantity of an item
void updateItemQuantity(Warehouse* warehouse, int id, int newQuantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i].quantity = newQuantity;
            printf("Updated item %s (ID: %d) to new quantity: %d\n", warehouse->items[i].name, id, newQuantity);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

// Function to display all items in the warehouse
void displayItems(Warehouse* warehouse) {
    if (warehouse->itemCount == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("Current items in warehouse:\n");
    printf("%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%-10d %-25s %-10d $%-9.2f\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

// Function to search for an item by ID
void searchItem(Warehouse* warehouse, int id) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (warehouse->items[i].id == id) {
            printf("Item found: %s (ID: %d) - Quantity: %d, Price: $%.2f\n", warehouse->items[i].name, id, warehouse->items[i].quantity, warehouse->items[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

// Main function
int main() {
    Warehouse warehouse;
    initWarehouse(&warehouse);

    int choice, id, quantity;
    char name[MAX_NAME_LENGTH];
    float price;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item Quantity\n");
        printf("4. Display Items\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf(" %[^\n]s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                printf("Enter item price: ");
                scanf("%f", &price);
                addItem(&warehouse, id, name, quantity, price);
                break;
            case 2:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                removeItem(&warehouse, id);
                break;
            case 3:
                printf("Enter item ID to update quantity: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, id, quantity);
                break;
            case 4:
                displayItems(&warehouse);
                break;
            case 5:
                printf("Enter item ID to search: ");
                scanf("%d", &id);
                searchItem(&warehouse, id);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}