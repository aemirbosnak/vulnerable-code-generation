//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

struct Item {
    char name[ITEM_NAME_LENGTH];
    int quantity;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int itemCount;
};

void initializeWarehouse(struct Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(struct Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    strcpy(warehouse->items[warehouse->itemCount].name, name);
    warehouse->items[warehouse->itemCount].quantity = quantity;
    warehouse->itemCount++;
    printf("Added %d of %s.\n", quantity, name);
}

void removeItem(struct Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->itemCount--;
            for (int j = i; j < warehouse->itemCount; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            printf("Removed %s from warehouse.\n", name);
            return;
        }
    }
    printf("%s not found in warehouse.\n", name);
}

void displayItems(struct Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("The warehouse is empty.\n");
        return;
    }
    printf("Current inventory:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("%s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    struct Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    char itemName[ITEM_NAME_LENGTH];
    int quantity;

    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline character
        
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(itemName, ITEM_NAME_LENGTH, stdin);
                itemName[strcspn(itemName, "\n")] = 0;  // Remove newline character
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, itemName, quantity);
                break;
            case 2:
                printf("Enter item name to remove: ");
                fgets(itemName, ITEM_NAME_LENGTH, stdin);
                itemName[strcspn(itemName, "\n")] = 0;  // Remove newline character
                removeItem(&warehouse, itemName);
                break;
            case 3:
                displayItems(&warehouse);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}