//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

// Warehouse data structure

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} item;

void printMenu() {
    printf("----------- WAREHOUSE MANAGEMENT SYSTEM -----------\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. List items\n");
    printf("4. Update item quantity\n");
    printf("5. Exit\n\n");
    printf("Enter your choice: ");
}

void addItem(item* inventory, int* numItems) {
    // check if warehouse is full
    if (*numItems == MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }

    // prompt user for item name
    char newItemName[MAX_NAME_LENGTH];
    printf("Enter the item name: ");
    scanf("%s", newItemName);

    // prompt user for item quantity
    int newItemQuantity;
    printf("Enter the item quantity: ");
    scanf("%d", &newItemQuantity);

    // add item to inventory
    strcpy(inventory[*numItems].name, newItemName);
    inventory[*numItems].quantity = newItemQuantity;

    // increment number of items in warehouse
    (*numItems)++;

    printf("Item added to warehouse!\n");
}

int findItemIndex(item* inventory, int numItems, char* itemName) {
    // linear search through inventory to find item
    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            return i;
        }
    }

    // item not found
    return -1;
}

void removeItem(item* inventory, int* numItems) {
    // prompt user for item name
    char itemName[MAX_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    scanf("%s", itemName);

    // find index of item to remove
    int itemIndex = findItemIndex(inventory, *numItems, itemName);

    // check if item was found
    if (itemIndex == -1) {
        printf("Item not found in warehouse!\n");
        return;
    }

    // remove item by shifting all subsequent items left by one
    for (int i = itemIndex; i < *numItems - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    // decrement number of items in warehouse
    (*numItems)--;

    printf("Item removed from warehouse!\n");
}

void listItems(item* inventory, int numItems) {
    if (numItems == 0) {
        printf("Warehouse is empty!\n");
        return;
    }

    printf("Warehouse inventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
    }
}

void updateItemQuantity(item* inventory, int numItems) {
    // prompt user for item name
    char itemName[MAX_NAME_LENGTH];
    printf("Enter the name of the item to update: ");
    scanf("%s", itemName);

    // find index of item to update
    int itemIndex = findItemIndex(inventory, numItems, itemName);

    // check if item was found
    if (itemIndex == -1) {
        printf("Item not found in warehouse!\n");
        return;
    }

    // prompt user for new item quantity
    int newQuantity;
    printf("Enter the new quantity for this item: ");
    scanf("%d", &newQuantity);

    // update item quantity
    inventory[itemIndex].quantity = newQuantity;

    printf("Item quantity updated!\n");
}

int main() {
    item inventory[MAX_ITEMS];
    int numItems = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &numItems);
                break;
            case 2:
                removeItem(inventory, &numItems);
                break;
            case 3:
                listItems(inventory, numItems);
                break;
            case 4:
                updateItemQuantity(inventory, numItems);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}