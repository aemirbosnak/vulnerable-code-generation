//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 30

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

void addItem(Item* inventory, int* itemCount) {
    if (*itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    
    printf("Enter item name: ");
    scanf("%s", inventory[*itemCount].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[*itemCount].quantity);
    printf("Enter item price: ");
    scanf("%f", &inventory[*itemCount].price);
    
    (*itemCount)++;
    printf("Item added successfully!\n");
}

void displayInventory(Item* inventory, int itemCount) {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("----------------------------------------------------\n");
    printf("| %15s | %8s | %10s |\n", "Item Name", "Quantity", "Price");
    printf("----------------------------------------------------\n");
    
    for (int i = 0; i < itemCount; i++) {
        printf("| %15s | %8d | $%9.2f |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    
    printf("----------------------------------------------------\n");
}

void searchItem(Item* inventory, int itemCount) {
    char searchName[ITEM_NAME_LENGTH];
    printf("Enter the item name to search: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Item found: %s, Quantity: %d, Price: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Display Inventory\n");
    printf("3. Search Item\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                displayInventory(inventory, itemCount);
                break;
            case 3:
                searchItem(inventory, itemCount);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}