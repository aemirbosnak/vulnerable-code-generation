//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem();
void removeItem();
void searchItem();
void viewInventory();
void menu();
void promptUserAction();

int main() {
    menu();
    return 0;
}

void menu() {
    printf("Welcome to the Warehouse Management System\n");
    while(1) {
        promptUserAction();
    }
}

void promptUserAction() {
    int choice;
    printf("\nChoose an action:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Search Item\n");
    printf("4. View Inventory\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            addItem();
            break;
        case 2:
            removeItem();
            break;
        case 3:
            searchItem();
            break;
        case 4:
            viewInventory();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    inventory[itemCount++] = newItem;
    printf("Added %s with quantity %d to inventory.\n", newItem.name, newItem.quantity);
}

void removeItem() {
    char name[ITEM_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    scanf("%s", name);
    int index = -1;

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found in inventory.\n");
        return;
    }

    for (int i = index; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    itemCount--;
    printf("Removed %s from inventory.\n", name);
}

void searchItem() {
    char name[ITEM_NAME_LENGTH];
    printf("Enter the name of the item to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Item found: %s, Quantity: %d\n", inventory[i].name, inventory[i].quantity);
            return;
        }
    }

    printf("Item not found in inventory.\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item: %s, Quantity: %d\n", inventory[i].name, inventory[i].quantity);
    }
}