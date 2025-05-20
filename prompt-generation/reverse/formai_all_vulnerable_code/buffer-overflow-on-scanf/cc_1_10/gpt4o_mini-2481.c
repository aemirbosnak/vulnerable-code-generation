//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
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

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1; // Simple ID assignment based on current count
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    inventory[itemCount] = newItem;
    itemCount++;

    printf("Item added: %s (ID: %d, Quantity: %d)\n", newItem.name, newItem.id, newItem.quantity);
}

void removeItem() {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }

    for (int i = id - 1; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;
    printf("Item with ID %d removed from inventory.\n", id);
}

void updateItem() {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }

    int index = id - 1;
    printf("Updating item: %s (Current Quantity: %d)\n", inventory[index].name, inventory[index].quantity);
    printf("Enter new quantity: ");
    scanf("%d", &inventory[index].quantity);
    printf("Item updated: %s (ID: %d, New Quantity: %d)\n", inventory[index].name, id, inventory[index].quantity);
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("Inventory Items:\n");
    printf("ID\tName\t\tQuantity\n");
    printf("-------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

void clearInventory() {
    itemCount = 0;
    printf("Inventory cleared.\n");
}

void showMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Update Item\n");
    printf("4. Display Items\n");
    printf("5. Clear Inventory\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                displayItems();
                break;
            case 5:
                clearInventory();
                break;
            case 6:
                printf("Exiting Warehouse Management System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}