//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    int id;
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

// Function prototypes
void initializeWarehouse(Warehouse *warehouse);
void addItem(Warehouse *warehouse);
void removeItem(Warehouse *warehouse);
void viewItems(Warehouse *warehouse);
int findItemIndex(Warehouse *warehouse, int id);

int main() {
    Warehouse warehouse;
    int choice;

    initializeWarehouse(&warehouse);

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Cannot add more items, warehouse is full.\n");
        return;
    }

    Item newItem;
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    getchar();  // Clear the newline character from the input buffer
    printf("Enter item name: ");
    fgets(newItem.name, ITEM_NAME_LENGTH, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline character
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully.\n");
}

void removeItem(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    
    int index = findItemIndex(warehouse, id);
    
    if (index == -1) {
        printf("Item with ID %d not found.\n", id);
        return;
    }
    
    for (int i = index; i < warehouse->count - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }

    warehouse->count--;
    printf("Item removed successfully.\n");
}

void viewItems(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("\nItems in Warehouse:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse->items[i].id,
               warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int findItemIndex(Warehouse *warehouse, int id) {
    for (int i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            return i;
        }
    }
    return -1; // Item not found
}