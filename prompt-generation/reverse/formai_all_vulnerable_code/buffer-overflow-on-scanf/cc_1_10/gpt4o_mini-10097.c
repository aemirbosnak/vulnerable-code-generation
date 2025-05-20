//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LEN 50

typedef struct {
    char name[ITEM_NAME_LEN];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->itemCount < MAX_ITEMS) {
        strncpy(warehouse->items[warehouse->itemCount].name, name, ITEM_NAME_LEN);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->itemCount++;
    } else {
        printf("Warehouse is full, cannot add more items.\n");
    }
}

void removeItem(Warehouse *warehouse, const char *name) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Removed %s from the warehouse.\n", name);
            return;
        }
    }
    printf("Item %s not found.\n", name);
}

void displayItems(const Warehouse *warehouse) {
    if (warehouse->itemCount == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("Items in the warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf(" - %s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    int choice;
    char name[ITEM_NAME_LEN];
    int quantity;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                addItem(&warehouse, name, quantity);
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
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}