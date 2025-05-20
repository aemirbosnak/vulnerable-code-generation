//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Inventory;

void displayMenu() {
    printf("\n--- Kingdom's Merchant Inventory System ---\n");
    printf("1. Add New Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Inventory\n");
    printf("4. Search for Item\n");
    printf("5. Update Item Quantity\n");
    printf("6. Exit\n");
    printf("Choose your option: ");
}

void addItem(Inventory *inv) {
    if (inv->count >= MAX_ITEMS) {
        printf("Thou hast reached the maximum number of items in the inventory.\n");
        return;
    }
    
    Item newItem;
    printf("Enter the name of the item: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &newItem.price);

    inv->items[inv->count] = newItem;
    inv->count++;
    printf("A new item hath been added to the inventory.\n");
}

void removeItem(Inventory *inv) {
    char itemName[NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, itemName) == 0) {
            for (int j = i; j < inv->count - 1; j++) {
                inv->items[j] = inv->items[j + 1];
            }
            inv->count--;
            printf("The item hath been removed from the inventory.\n");
            return;
        }
    }
    printf("No such item found in the inventory.\n");
}

void displayInventory(Inventory *inv) {
    if (inv->count == 0) {
        printf("The inventory is empty, good merchant!\n");
        return;
    }
    
    printf("\n--- Current Inventory ---\n");
    for (int i = 0; i < inv->count; i++) {
        printf("Item: %s | Quantity: %d | Price: %.2f gold coins\n", 
            inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
    }
}

void searchItem(Inventory *inv) {
    char itemName[NAME_LENGTH];
    printf("Enter the name of the item to search: ");
    scanf(" %[^\n]", itemName);

    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, itemName) == 0) {
            printf("Item: %s | Quantity: %d | Price: %.2f gold coins\n", 
                inv->items[i].name, inv->items[i].quantity, inv->items[i].price);
            return;
        }
    }
    printf("No such item found in the inventory, noble merchant.\n");
}

void updateItemQuantity(Inventory *inv) {
    char itemName[NAME_LENGTH];
    int newQuantity;
    printf("Enter the name of the item to update: ");
    scanf(" %[^\n]", itemName);
 
    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].name, itemName) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &newQuantity);
            inv->items[i].quantity = newQuantity;
            printf("The quantity hath been updated.\n");
            return;
        }
    }
    printf("No such item found in the inventory.\n");
}

int main() {
    Inventory inv;
    inv.count = 0;

    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addItem(&inv); break;
            case 2: removeItem(&inv); break;
            case 3: displayInventory(&inv); break;
            case 4: searchItem(&inv); break;
            case 5: updateItemQuantity(&inv); break;
            case 6: printf("Farewell, noble merchant! May your transactions be bountiful.\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}