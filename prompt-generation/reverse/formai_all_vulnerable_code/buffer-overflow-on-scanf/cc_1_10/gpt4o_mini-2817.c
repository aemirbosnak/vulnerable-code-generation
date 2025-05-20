//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void initializeInventory(Inventory *inv) {
    inv->count = 0;
}

void addItem(Inventory *inv) {
    if (inv->count >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }
    
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    
    inv->items[inv->count] = newItem;
    inv->count++;
    printf("Item added successfully!\n");
}

void displayItems(Inventory *inv) {
    if (inv->count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    
    printf("\n--- Inventory Items ---\n");
    for (int i = 0; i < inv->count; i++) {
        printf("Item %d: %s, Quantity: %d, Price: %.2f\n",
            i + 1, inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

void sellItem(Inventory *inv) {
    char itemName[NAME_LENGTH];
    int quantity;
    
    printf("Enter item name to sell: ");
    scanf("%s", itemName);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, itemName) == 0) {
            if (inv->items[i].quantity >= quantity) {
                inv->items[i].quantity -= quantity;
                printf("Sold %d of %s!\n", quantity, itemName);
                return;
            } else {
                printf("Insufficient quantity available!\n");
                return;
            }
        }
    }
    
    printf("Item not found!\n");
}

void restockItem(Inventory *inv) {
    char itemName[NAME_LENGTH];
    int quantity;
    
    printf("Enter item name to restock: ");
    scanf("%s", itemName);
    printf("Enter quantity to restock: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, itemName) == 0) {
            inv->items[i].quantity += quantity;
            printf("Restocked %d of %s!\n", quantity, itemName);
            return;
        }
    }
    
    printf("Item not found, consider adding it instead!\n");
}

void menu() {
    printf("\n--- Inventory Management System ---\n");
    printf("1. Add Item\n");
    printf("2. Display Items\n");
    printf("3. Sell Item\n");
    printf("4. Restock Item\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    Inventory inventory;
    initializeInventory(&inventory);
    
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&inventory);
                break;
            case 2:
                displayItems(&inventory);
                break;
            case 3:
                sellItem(&inventory);
                break;
            case 4:
                restockItem(&inventory);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}