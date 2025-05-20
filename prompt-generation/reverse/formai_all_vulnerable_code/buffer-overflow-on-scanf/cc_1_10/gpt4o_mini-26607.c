//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int item_count = 0;

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }

    char item_name[ITEM_NAME_LENGTH];
    int quantity;

    printf("Enter item name: ");
    scanf("%s", item_name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(warehouse[i].name, item_name) == 0) {
            warehouse[i].quantity += quantity;
            printf("Updated %s quantity to %d.\n", warehouse[i].name, warehouse[i].quantity);
            return;
        }
    }

    strcpy(warehouse[item_count].name, item_name);
    warehouse[item_count].quantity = quantity;
    item_count++;

    printf("Added %s with quantity %d to the warehouse.\n", item_name, quantity);
}

void remove_item() {
    char item_name[ITEM_NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", item_name);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(warehouse[i].name, item_name) == 0) {
            printf("Removing %s with quantity %d from the warehouse.\n", warehouse[i].name, warehouse[i].quantity);
            warehouse[i] = warehouse[item_count - 1];  // Replace with last item
            item_count--;
            return;
        }
    }

    printf("Item %s not found in the warehouse.\n", item_name);
}

void display_inventory() {
    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < item_count; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
    printf("\n");
}

void search_item() {
    char item_name[ITEM_NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", item_name);

    for (int i = 0; i < item_count; i++) {
        if (strcmp(warehouse[i].name, item_name) == 0) {
            printf("Item found: %s, Quantity: %d\n", warehouse[i].name, warehouse[i].quantity);
            return;
        }
    }

    printf("Item %s not found in the warehouse.\n", item_name);
}

void show_menu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Display Inventory\n");
    printf("4. Search Item\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                search_item();
                break;
            case 5:
                printf("Exiting the Warehouse Management System.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}