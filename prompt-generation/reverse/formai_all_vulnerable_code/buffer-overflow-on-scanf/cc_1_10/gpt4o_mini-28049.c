//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} WarehouseItem;

WarehouseItem inventory[MAX_ITEMS];
int itemCount = 0;

void addItem(const char *name, int quantity) {
    if (itemCount < MAX_ITEMS) {
        strcpy(inventory[itemCount].name, name);
        inventory[itemCount].quantity = quantity;
        itemCount++;
        printf("Added %d of %s to inventory.\n", quantity, name);
    } else {
        printf("Inventory full! Cannot add more items.\n");
    }
}

void removeItem(const char *name, int quantity) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                printf("Removed %d of %s from inventory.\n", quantity, name);
                if (inventory[i].quantity == 0) {
                    for (int j = i; j < itemCount - 1; j++) {
                        inventory[j] = inventory[j + 1];
                    }
                    itemCount--;
                }
                return;
            } else {
                printf("Not enough %s in inventory to remove %d.\n", name, quantity);
                return;
            }
        }
    }
    printf("%s not found in inventory.\n", name);
}

void displayInventory() {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
    }
}

void searchItem(const char *name) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found %s: %d in inventory.\n", name, inventory[i].quantity);
            return;
        }
    }
    printf("%s not found in inventory.\n", name);
}

int main() {
    int choice;
    char itemName[ITEM_NAME_LENGTH];
    int quantity;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addItem(itemName, quantity);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);
                removeItem(itemName, quantity);
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Enter item name to search: ");
                scanf("%s", itemName);
                searchItem(itemName);
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}