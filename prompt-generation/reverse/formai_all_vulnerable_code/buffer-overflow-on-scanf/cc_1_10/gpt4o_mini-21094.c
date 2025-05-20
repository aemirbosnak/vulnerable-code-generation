//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
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

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem();
void viewItems();
void removeItem();
void searchItem();

int main() {
    int choice;

    while (1) {
        printf("\n--- Warehouse Management System ---\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Remove Item\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                searchItem();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    Item newItem;
    newItem.id = itemCount + 1;

    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    inventory[itemCount] = newItem;
    itemCount++;

    printf("Item added successfully!\n");
}

void viewItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\nInventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
}

void removeItem() {
    if (itemCount == 0) {
        printf("No items to remove.\n");
        return;
    }

    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", id);
}

void searchItem() {
    if (itemCount == 0) {
        printf("No items to search.\n");
        return;
    }

    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", name);

    printf("\nSearch Results:\n");
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("ID: %d, Name: %s, Quantity: %d\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("No item with name '%s' found.\n", name);
    }
}