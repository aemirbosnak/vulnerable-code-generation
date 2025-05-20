//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    int id;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int current_size;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->current_size = 0;
}

int addItem(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->current_size >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return -1;
    }

    for (int i = 0; i < warehouse->current_size; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity += quantity;
            printf("Updated %s quantity to %d.\n", name, warehouse->items[i].quantity);
            return 0;
        }
    }

    Item new_item;
    strncpy(new_item.name, name, NAME_LENGTH);
    new_item.quantity = quantity;
    new_item.id = warehouse->current_size + 1;
    warehouse->items[warehouse->current_size++] = new_item;
    
    printf("Added new item: %s, Quantity: %d, ID: %d\n", new_item.name, new_item.quantity, new_item.id);
    return 0;
}

void removeItem(Warehouse *warehouse, const char *name, int quantity) {
    for (int i = 0; i < warehouse->current_size; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (warehouse->items[i].quantity >= quantity) {
                warehouse->items[i].quantity -= quantity;
                printf("Removed %d of %s. Remaining quantity: %d\n", quantity, name, warehouse->items[i].quantity);
                
                if (warehouse->items[i].quantity == 0) {
                    warehouse->items[i] = warehouse->items[warehouse->current_size - 1];
                    warehouse->current_size--;
                    printf("Removed %s completely from warehouse.\n", name);
                }
                
                return;
            } else {
                printf("Not enough quantity to remove. Current quantity: %d\n", warehouse->items[i].quantity);
                return;
            }
        }
    }
    printf("Item %s not found in the warehouse.\n", name);
}

void displayWarehouse(const Warehouse *warehouse) {
    if (warehouse->current_size == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    printf("Current items in the warehouse:\n");
    for (int i = 0; i < warehouse->current_size; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse->items[i].id, warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    
    char action[10];
    char item_name[NAME_LENGTH];
    int quantity;

    printf("Welcome to the Post-Apocalyptic Warehouse Management System!\n");

    while (1) {
        printf("\nEnter action (add, remove, display, exit): ");
        scanf("%s", action);

        if (strcmp(action, "add") == 0) {
            printf("Enter item name: ");
            scanf("%s", item_name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            addItem(&warehouse, item_name, quantity);
        }
        else if (strcmp(action, "remove") == 0) {
            printf("Enter item name: ");
            scanf("%s", item_name);
            printf("Enter quantity to remove: ");
            scanf("%d", &quantity);
            removeItem(&warehouse, item_name, quantity);
        }
        else if (strcmp(action, "display") == 0) {
            displayWarehouse(&warehouse);
        }
        else if (strcmp(action, "exit") == 0) {
            printf("Exiting the warehouse management system. Stay safe out there!\n");
            break;
        }
        else {
            printf("Unknown action. Please try again.\n");
        }
    }

    return 0;
}