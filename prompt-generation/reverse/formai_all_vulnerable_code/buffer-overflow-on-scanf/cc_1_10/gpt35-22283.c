//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item stock[MAX_STOCK];
    int count;
} Inventory;

void displayMainMenu();
void addItems(Inventory *inv);
void sellItems(Inventory *inv);
void displayInventory(Inventory *inv);

int main() {
    Inventory inventory;
    inventory.count = 0;

    int choice;

    do {
        displayMainMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItems(&inventory);
                break;
            case 2:
                sellItems(&inventory);
                break;
            case 3:
                displayInventory(&inventory);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(choice != 4);

    return 0;
}

void displayMainMenu() {
    printf("\n");
    printf("**** C Medical Store Management System ****\n");
    printf("1. Add items to inventory\n");
    printf("2. Sell items from inventory\n");
    printf("3. Display inventory\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

void addItems(Inventory *inv) {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;

    printf("\nEnter item name: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    if (inv->count == MAX_STOCK) {
        printf("Inventory is full. Cannot add any more items.\n");
        return;
    }

    Item newItem;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;
    newItem.price = price;

    inv->stock[inv->count++] = newItem;

    printf("Item added to inventory.\n");
}

void sellItems(Inventory *inv) {
    char name[MAX_NAME_LENGTH];
    int quantity;

    printf("\nEnter item name: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < inv->count; i++) {
        if (strcmp(inv->stock[i].name, name) == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity > inv->stock[i].quantity) {
                printf("Not enough items in inventory. Sold only %d items.\n", inv->stock[i].quantity);
                inv->stock[i].quantity = 0;
            } else {
                inv->stock[i].quantity -= quantity;
                printf("%d items sold.\n", quantity);
            }

            return;
        }
    }

    printf("Item not found in inventory.\n");
}

void displayInventory(Inventory *inv) {
    printf("\nInventory:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");

    int i;
    for (i = 0; i < inv->count; i++) {
        printf("%-20s %-10d %-10.2f\n", inv->stock[i].name, inv->stock[i].quantity, inv->stock[i].price);
    }
}