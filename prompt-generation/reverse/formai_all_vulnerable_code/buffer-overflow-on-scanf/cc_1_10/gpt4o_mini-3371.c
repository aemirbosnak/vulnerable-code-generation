//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    
    warehouse[itemCount] = newItem;
    itemCount++;
    printf("Item '%s' added successfully!\n", newItem.name);
}

void removeItem() {
    char itemName[ITEM_NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", itemName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(warehouse[i].name, itemName) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                warehouse[j] = warehouse[j + 1]; // Shift items left
            }
            itemCount--;
            printf("Item '%s' removed successfully!\n", itemName);
            return;
        }
    }
    printf("Item '%s' not found in warehouse.\n", itemName);
}

void displayInventory() {
    if (itemCount == 0) {
        printf("Warehouse is empty!\n");
        return;
    }
    printf("Current Inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item Name: %s, Quantity: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

void updateItemQuantity() {
    char itemName[ITEM_NAME_LENGTH];
    int newQuantity;
    printf("Enter item name to update quantity: ");
    scanf("%s", itemName);
    printf("Enter new quantity: ");
    scanf("%d", &newQuantity);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(warehouse[i].name, itemName) == 0) {
            warehouse[i].quantity = newQuantity;
            printf("Item '%s' quantity updated to %d!\n", itemName, newQuantity);
            return;
        }
    }
    printf("Item '%s' not found in warehouse.\n", itemName);
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Display inventory\n");
    printf("4. Update item quantity\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                updateItemQuantity();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select an option between 1 and 5.\n");
        }
    }
    
    return 0;
}