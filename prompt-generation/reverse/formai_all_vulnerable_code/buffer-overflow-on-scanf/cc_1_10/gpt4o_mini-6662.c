//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct Item {
    char name[NAME_LENGTH];
    int quantity;
} Item;

typedef struct Warehouse {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->itemCount < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->itemCount].name, name);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->itemCount++;
        printf("Added %d of '%s' to the warehouse!\n", quantity, name);
    } else {
        printf("Warehouse is full! Cannot add any more items.\n");
    }
}

void removeItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Removing '%s' from the warehouse!\n", name);
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            return;
        }
    }
    printf("Item '%s' not found in the warehouse.\n", name);
}

void displayInventory(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("The warehouse is empty!\n");
        return;
    }
    printf("Current Warehouse Inventory:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%d. %s - %d units\n", i + 1, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void updateItemQuantity(Warehouse *warehouse, const char *name, int quantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity += quantity;
            printf("Updated '%s' quantity to %d!\n", name, warehouse->items[i].quantity);
            return;
        }
    }
    printf("Item '%s' not found! Adding it to the warehouse instead.\n", name);
    addItem(warehouse, name, quantity);
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    char itemName[NAME_LENGTH];
    int quantity;

    do {
        printf("\nWelcome to the Warehouse Management System!\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Update Item Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, itemName, quantity);
                break;

            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", itemName);
                removeItem(&warehouse, itemName);
                break;

            case 3:
                displayInventory(&warehouse);
                break;

            case 4:
                printf("Enter item name to update: ");
                scanf("%s", itemName);
                printf("Enter quantity to add/subtract (-ve for subtraction): ");
                scanf("%d", &quantity);
                updateItemQuantity(&warehouse, itemName, quantity);
                break;

            case 5:
                printf("Exiting the Warehouse Management System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}