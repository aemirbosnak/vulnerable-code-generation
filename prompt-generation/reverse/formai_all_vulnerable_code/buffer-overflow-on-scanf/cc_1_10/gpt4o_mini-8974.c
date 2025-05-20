//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: energetic
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

void add_item(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->itemCount < MAX_ITEMS) {
        strcpy(warehouse->items[warehouse->itemCount].name, name);
        warehouse->items[warehouse->itemCount].quantity = quantity;
        warehouse->itemCount++;
        printf("Added %d of item '%s' to the warehouse!\n", quantity, name);
    } else {
        printf("Warehouse is full! Cannot add more items.\n");
    }
}

void remove_item(Warehouse *warehouse, const char *name, int quantity) {
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (warehouse->items[i].quantity >= quantity) {
                warehouse->items[i].quantity -= quantity;
                printf("Removed %d of item '%s' from the warehouse!\n", quantity, name);
                if (warehouse->items[i].quantity == 0) {
                    printf("Item '%s' is out of stock!\n", name);
                }
            } else {
                printf("Not enough of item '%s' in stock to remove! Current quantity: %d\n", name, warehouse->items[i].quantity);
            }
            return;
        }
    }
    printf("Item '%s' not found in the warehouse!\n", name);
}

void check_stock(Warehouse *warehouse) {
    printf("\nCurrent Stock Levels:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

void display_menu() {
    printf("\n--- Warehouse Management System Menu ---\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Check Stock\n");
    printf("4. Exit\n");
}

int main() {
    Warehouse warehouse = {.itemCount = 0};
    int choice;
    char name[ITEM_NAME_LENGTH];
    int quantity;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
                printf("Enter item name to add: ");
                scanf("%s", name);
                printf("Enter quantity to add: ");
                scanf("%d", &quantity);
                add_item(&warehouse, name, quantity);
                break;
          case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);
                remove_item(&warehouse, name, quantity);
                break;
          case 3:
                check_stock(&warehouse);
                break;
          case 4:
                printf("Exiting the program. Thank you for using the Warehouse Management System!\n");
                exit(0);
          default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}