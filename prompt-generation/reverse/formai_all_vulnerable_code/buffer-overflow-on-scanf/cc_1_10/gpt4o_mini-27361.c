//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
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

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }
    Item newItem;

    printf("Enter item name: ");
    scanf(" %[^\n]", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void removeItem() {
    char name[NAME_LENGTH];

    printf("Enter item name to remove: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void displayInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("Current Inventory:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    char name[NAME_LENGTH];

    printf("Enter item name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Item Found: %s, Quantity: %d, Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found in inventory.\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Inventory\n");
    printf("4. Search Item\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
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
                searchItem();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}