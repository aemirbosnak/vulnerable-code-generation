//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define ITEM_LENGTH 20

struct Item {
    char name[ITEM_LENGTH];
    int quantity, price;
};

struct Warehouse {
    struct Item items[MAX_ITEMS];
    int num_items;
};

void addItem(struct Warehouse *warehouse, char *name, int quantity, int price) {
    if (warehouse->num_items == MAX_ITEMS) {
        printf("Warehouse is full, cannot add item\n");
    } else {
        struct Item *new_item = &(warehouse->items[warehouse->num_items++]);
        strcpy(new_item->name, name);
        new_item->quantity = quantity;
        new_item->price = price;
        printf("Added item %s with quantity %d and price %d\n", new_item->name, new_item->quantity, new_item->price);
    }
}

void removeItem(struct Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Removed item %s with quantity %d and price %d\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
            for (int j = i; j < warehouse->num_items - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->num_items--;
            return;
        }
    }
    printf("Could not find item %s, cannot remove\n", name);
}

void printWarehouse(struct Warehouse *warehouse) {
    printf("Warehouse has %d items:\n", warehouse->num_items);
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%d. %s\t%d\t$%d\n", i + 1, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    struct Warehouse warehouse;
    warehouse.num_items = 0;
    while (1) {
        printf("Enter command (add/remove/print/exit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char name[ITEM_LENGTH];
            printf("Enter item name: ");
            scanf("%s", name);
            int quantity, price;
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%d", &price);
            addItem(&warehouse, name, quantity, price);
        } else if (strcmp(command, "remove") == 0) {
            char name[ITEM_LENGTH];
            printf("Enter item name: ");
            scanf("%s", name);
            removeItem(&warehouse, name);
        } else if (strcmp(command, "print") == 0) {
            printWarehouse(&warehouse);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command, try again\n");
        }
    }
    printf("Goodbye!\n");
    return 0;
}