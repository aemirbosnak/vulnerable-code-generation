//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

// Function declarations
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void displayItems(const Warehouse *warehouse);
void findItem(const Warehouse *warehouse);
int getMenuChoice();

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;

    while ((choice = getMenuChoice()) != 5) {
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
                findItem(&warehouse);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    printf("Exiting Warehouse Management System. Goodbye!\n");
    return 0;
}

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
    printf("Warehouse initialized.\n");
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
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

    warehouse->items[warehouse->count++] = newItem;
    printf("Item added successfully.\n");
}

void removeItem(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->count; ++i) {
        if (warehouse->items[i].id == id) {
            warehouse->items[i] = warehouse->items[--warehouse->count];
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    
    printf("Items in the warehouse:\n");
    for (int i = 0; i < warehouse->count; ++i) {
        printf("ID: %d, Name: %s, Quantity: %d\n", 
               warehouse->items[i].id,
               warehouse->items[i].name,
               warehouse->items[i].quantity);
    }
}

void findItem(const Warehouse *warehouse) {
    int id;
    printf("Enter item ID to find: ");
    scanf("%d", &id);
    
    for (int i = 0; i < warehouse->count; ++i) {
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

int getMenuChoice() {
    int choice;
    printf("\nWarehouse Management System Menu:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Items\n");
    printf("4. Find Item\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}