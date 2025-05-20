//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *w) {
    w->itemCount = 0;
}

void addItem(Warehouse *w) {
    if (w->itemCount >= MAX_ITEMS) {
        printf("Sorry, the warehouse is full! Can't add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);

    w->items[w->itemCount] = newItem;
    w->itemCount++;
    printf("Yay! Added %d of %s to the warehouse!\n", newItem.quantity, newItem.name);
}

void removeItem(Warehouse *w) {
    char itemName[ITEM_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    scanf("%s", itemName);

    for (int i = 0; i < w->itemCount; i++) {
        if (strcmp(w->items[i].name, itemName) == 0) {
            printf("Removing %d of %s from the warehouse!\n", w->items[i].quantity, w->items[i].name);
            for (int j = i; j < w->itemCount - 1; j++) {
                w->items[j] = w->items[j + 1];
            }
            w->itemCount--;
            return;
        }
    }
    printf("Oops! %s is not found in the warehouse.\n", itemName);
}

void displayInventory(const Warehouse *w) {
    printf("\n--- Current Warehouse Inventory ---\n");
    if (w->itemCount == 0) {
        printf("The warehouse is empty! Let's add some items!\n");
        return;
    }
    for (int i = 0; i < w->itemCount; i++) {
        printf("Item: %s | Quantity: %d\n", w->items[i].name, w->items[i].quantity);
    }
    printf("-----------------------------------\n");
}

void warehouseMenu() {
    printf("\nWelcome to the Warehouse Management System!\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Inventory\n");
    printf("4. Exit\n");
}

int main() {
    Warehouse myWarehouse;
    initializeWarehouse(&myWarehouse);

    int choice;

    while (1) {
        warehouseMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&myWarehouse);
                break;
            case 2:
                removeItem(&myWarehouse);
                break;
            case 3:
                displayInventory(&myWarehouse);
                break;
            case 4:
                printf("Exiting the Warehouse Management System. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}