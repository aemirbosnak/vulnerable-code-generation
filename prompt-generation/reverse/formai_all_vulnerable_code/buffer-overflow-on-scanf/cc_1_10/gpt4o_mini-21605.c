//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct Item {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct Warehouse {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse* warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse* warehouse, const char* name, int quantity, float price) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    strcpy(warehouse->items[warehouse->itemCount].name, name);
    warehouse->items[warehouse->itemCount].quantity = quantity;
    warehouse->items[warehouse->itemCount].price = price;
    warehouse->itemCount++;
    printf("Added %s to the warehouse.\n", name);
}

void removeItem(Warehouse* warehouse, const char* name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->itemCount - 1];
            warehouse->itemCount--;
            printf("Removed %s from the warehouse.\n", name);
            return;
        }
    }
    printf("Item not found!\n");
}

void displayItems(const Warehouse* warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in the warehouse.\n");
        return;
    }
    printf("Items in the warehouse:\n");
    printf("%-25s %-10s %-10s\n", "Item Name", "Quantity", "Price");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%-25s %-10d $%-9.2f\n", warehouse->items[i].name,
               warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void updateItem(Warehouse* warehouse, const char* name, int quantity, float price) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity = quantity;
            warehouse->items[i].price = price;
            printf("Updated %s in the warehouse.\n", name);
            return;
        }
    }
    printf("Item not found!\n");
}

void searchItem(const Warehouse* warehouse, const char* name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Item found: %s, Quantity: %d, Price: $%.2f\n", 
                   warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);

    int choice;
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Update Item\n");
        printf("5. Search Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addItem(&warehouse, name, quantity, price);
                break;
            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                removeItem(&warehouse, name);
                break;
            case 3:
                displayItems(&warehouse);
                break;
            case 4:
                printf("Enter item name to update: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                printf("Enter new price: ");
                scanf("%f", &price);
                updateItem(&warehouse, name, quantity, price);
                break;
            case 5:
                printf("Enter item name to search: ");
                scanf("%s", name);
                searchItem(&warehouse, name);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}