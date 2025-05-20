//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20

typedef struct InventoryItem {
    char name[MAX_NAME_LEN];
    int quantity;
} InventoryItem;

int itemCount = 0;
InventoryItem inventory[MAX_ITEMS];

void addItemToInventory(char name[], int quantity) {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory capacity is full. Cannot add more items.\n");
        return;
    }
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            inventory[i].quantity += quantity;
            printf("%d %s added to inventory.\n", quantity, name);
            return;
        }
    }
    
    strcpy(inventory[itemCount].name, name);
    inventory[itemCount].quantity = quantity;
    itemCount++;
    printf("%d %s added to inventory.\n", quantity, name);
}

void displayInventory() {
    printf("Current inventory:\n");
    printf("---------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d %s\n", inventory[i].quantity, inventory[i].name);
    }
    printf("---------------\n");
}

void removeItemFromInventory(char name[], int quantity) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            if (inventory[i].quantity < quantity) {
                printf("Cannot remove %d %s, only %d available in inventory.\n", quantity, name, inventory[i].quantity);
                return;
            }
            inventory[i].quantity -= quantity;
            printf("%d %s removed from inventory.\n", quantity, name);
            return;
        }
    }
    printf("%s not found in inventory. Unable to remove.\n", name);
}

int main() {
    int choice, quantity;
    char name[MAX_NAME_LEN];
    
    while (1) {
        printf("Select an option:\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addItemToInventory(name, quantity);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                removeItemFromInventory(name, quantity);
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}