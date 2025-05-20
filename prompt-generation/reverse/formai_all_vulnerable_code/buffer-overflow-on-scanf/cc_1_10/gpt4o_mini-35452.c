//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem();
void removeItem();
void viewInventory();
void menu();

void addItem() {
    if(itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        menu();
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
    menu();
}

void removeItem() {
    char itemName[50];
    printf("Enter item name to remove: ");
    scanf("%s", itemName);
    
    for(int i = 0; i < itemCount; i++) {
        if(strcmp(inventory[i].name, itemName) == 0) {
            for(int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift items left
            }
            itemCount--;
            printf("Item removed successfully!\n");
            menu();
            return;
        }
    }
    printf("Item not found in inventory.\n");
    menu();
}

void viewInventory() {
    if(itemCount == 0) {
        printf("Inventory is empty.\n");
    } else {
        printf("Current Inventory:\n");
        for(int i = 0; i < itemCount; i++) {
            printf("Item Name: %s, Quantity: %d\n", inventory[i].name, inventory[i].quantity);
        }
    }
    menu();
}

void menu() {
    int choice;
    printf("\nWarehouse Management System Menu:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Inventory\n");
    printf("4. Exit\n");
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
            viewInventory();
            break;
        case 4:
            printf("Exiting system. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            menu();
            break;
    }
}

int main() {
    printf("Welcome to the Warehouse Management System\n");
    menu();
    return 0;
}