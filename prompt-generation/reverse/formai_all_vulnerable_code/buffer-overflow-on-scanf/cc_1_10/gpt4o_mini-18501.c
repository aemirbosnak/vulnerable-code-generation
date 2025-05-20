//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
    printf("Welcome to the Warehouse Management System! 🎉\n");
}

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items. 😢\n");
        return;
    }

    Item newItem;
    newItem.id = warehouse->itemCount + 1;
    printf("Enter the name of the item: ");
    scanf("%s", newItem.name);
    printf("Enter the quantity of the item: ");
    scanf("%d", &newItem.quantity);

    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    printf("Item '%s' added successfully! 🎉\n", newItem.name);
}

void displayItems(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse. 😞\n");
        return;
    }

    printf("\nCurrent Items in Warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse->items[i].id,
               warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void removeItem(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items to remove. 😞\n");
        return;
    }

    int id;
    printf("Enter the ID of the item to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > warehouse->itemCount) {
        printf("Invalid item ID! Please try again. 🙁\n");
        return;
    }

    for (int i = id - 1; i < warehouse->itemCount - 1; i++) {
        warehouse->items[i] = warehouse->items[i + 1];
    }
    warehouse->itemCount--;
    printf("Item with ID %d removed successfully! 🎉\n", id);
}

void searchItem(Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse to search! 😞\n");
        return;
    }

    char name[50];
    printf("Enter the name of the item to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Item found! ID: %d, Quantity: %d\n", warehouse->items[i].id,
                   warehouse->items[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Item '%s' not found in the warehouse. 😞\n", name);
}

void warehouseMenu() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;

    do {
        printf("\n📦 Warehouse Menu 📦\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Remove Item\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                searchItem(&warehouse);
                break;
            case 5:
                printf("Thank you for using the Warehouse Management System! 😊\n");
                break;
            default:
                printf("Invalid choice! Please try again. 🙁\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    warehouseMenu();
    return 0;
}