//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    int id;
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount < MAX_ITEMS) {
        Item newItem;
        newItem.id = warehouse->itemCount + 1;

        printf("Enter item name: ");
        scanf(" %[^\n]", newItem.name);
        printf("Enter item quantity: ");
        scanf("%d", &newItem.quantity);
        printf("Enter item price: ");
        scanf("%f", &newItem.price);

        warehouse->items[warehouse->itemCount] = newItem;
        warehouse->itemCount++;

        printf("Item added successfully! ID: %d\n", newItem.id);
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("\nItems in Warehouse:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        Item item = warehouse->items[i];
        printf("%d\t%s\t%d\t\t%.2f\n", item.id, item.name, item.quantity, item.price);
    }
}

void removeItem(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > warehouse->itemCount) {
        printf("Invalid ID! No item removed.\n");
        return;
    }

    for (int i = id - 1; i < warehouse->itemCount - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->itemCount--;

    printf("Item with ID %d removed successfully!\n", id);
}

void updateItem(Warehouse *warehouse) {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > warehouse->itemCount) {
        printf("Invalid ID! No item updated.\n");
        return;
    }

    Item *item = &warehouse->items[id - 1];
    printf("Updating item ID: %d\n", item->id);
    printf("Current name: %s\n", item->name);
    printf("Enter new name (or press Enter to keep current): ");
    char newName[ITEM_NAME_LENGTH];
    scanf(" %[^\n]", newName);
    if (strlen(newName) > 0) {
        strcpy(item->name, newName);
    }
    printf("Current quantity: %d\n", item->quantity);
    printf("Enter new quantity (or -1 to keep current): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity != -1) {
        item->quantity = newQuantity;
    }
    printf("Current price: %.2f\n", item->price);
    printf("Enter new price (or -1 to keep current): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice != -1) {
        item->price = newPrice;
    }

    printf("Item updated successfully!\n");
}

void warehouseMenu() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Remove Item\n");
        printf("4. Update Item\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                displayItems(&warehouse);
                break;
            case 3:
                removeItem(&warehouse);
                break;
            case 4:
                updateItem(&warehouse);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    warehouseMenu();
    return 0;
}