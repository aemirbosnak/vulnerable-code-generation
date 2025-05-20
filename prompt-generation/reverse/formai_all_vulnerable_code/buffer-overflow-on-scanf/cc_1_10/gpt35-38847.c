//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

typedef struct WarehouseItem {
    char name[MAX_NAME_LENGTH];
    int quantity;
} WarehouseItem;

WarehouseItem warehouse[MAX_ITEMS];
int total_items = 0;

void add_item(char* name, int quantity) {
    if (total_items >= MAX_ITEMS) {
        printf("Error: Warehouse is full!\n");
        return;
    }

    int existing_item_index = -1;
    for (int i = 0; i < total_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            existing_item_index = i;
            break;
        }
    }

    if (existing_item_index == -1) {
        // Add new item
        WarehouseItem new_item;
        strcpy(new_item.name, name);
        new_item.quantity = quantity;
        warehouse[total_items] = new_item;
        total_items++;
        printf("Item added successfully.\n");
    } else {
        // Update existing item
        warehouse[existing_item_index].quantity += quantity;
        printf("Item quantity updated successfully.\n");
    }
}

void remove_item(char* name, int quantity) {
    int existing_item_index = -1;
    for (int i = 0; i < total_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            existing_item_index = i;
            break;
        }
    }

    if (existing_item_index == -1) {
        printf("Error: Item not found!\n");
    } else if (warehouse[existing_item_index].quantity < quantity) {
        printf("Error: Not enough quantity of item in stock!\n");
    } else {
        // Remove item
        warehouse[existing_item_index].quantity -= quantity;
        printf("Item removed successfully.\n");
    }
}

void show_inventory() {
    printf("%-20s %-10s\n", "Item", "Quantity");
    printf("------------------------------\n");
    for (int i = 0; i < total_items; i++) {
        printf("%-20s %-10d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    int option;
    char item_name[MAX_NAME_LENGTH];
    int item_quantity;

    while(1) {
        printf("Welcome to Warehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Show inventory\n");
        printf("4. Quit\n");
        printf("Enter option: ");

        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", item_name);
                printf("Enter quantity: ");
                scanf("%d", &item_quantity);
                add_item(item_name, item_quantity);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", item_name);
                printf("Enter quantity: ");
                scanf("%d", &item_quantity);
                remove_item(item_name, item_quantity);
                break;
            case 3:
                show_inventory();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option, try again.\n");
                break;
        }
    }

    return 0;
}