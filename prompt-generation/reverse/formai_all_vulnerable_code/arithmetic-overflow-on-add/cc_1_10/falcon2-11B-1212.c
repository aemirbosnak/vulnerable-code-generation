//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_ITEM_NAME 20
#define MAX_QUANTITY 5

typedef struct {
    char item_name[MAX_ITEM_NAME];
    int quantity;
} Item;

typedef struct {
    int id;
    Item items[MAX_ITEMS];
} Warehouse;

void add_item(Warehouse* warehouse, const char* item_name, int quantity) {
    if (warehouse->id >= MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }

    strcpy(warehouse->items[warehouse->id].item_name, item_name);
    warehouse->items[warehouse->id].quantity = quantity;
    warehouse->id++;
}

void remove_item(Warehouse* warehouse, const char* item_name) {
    int i;
    for (i = 0; i < warehouse->id; i++) {
        if (strcmp(warehouse->items[i].item_name, item_name) == 0) {
            strcpy(warehouse->items[i].item_name, "");
            warehouse->items[i].quantity = 0;
            break;
        }
    }
}

void update_item(Warehouse* warehouse, const char* item_name, int quantity) {
    int i;
    for (i = 0; i < warehouse->id; i++) {
        if (strcmp(warehouse->items[i].item_name, item_name) == 0) {
            warehouse->items[i].quantity = quantity;
            break;
        }
    }
}

void print_inventory(const Warehouse* warehouse) {
    int i;
    printf("Warehouse ID: %d\n", warehouse->id);
    for (i = 0; i < warehouse->id; i++) {
        printf("Item: %s, Quantity: %d\n", warehouse->items[i].item_name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    warehouse.id = 0;

    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. Update item\n4. Print inventory\n5. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", warehouse.items[warehouse.id].item_name);
                printf("Enter quantity: ");
                scanf("%d", &warehouse.items[warehouse.id].quantity);
                add_item(&warehouse, warehouse.items[warehouse.id].item_name, warehouse.items[warehouse.id].quantity);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", warehouse.items[warehouse.id].item_name);
                remove_item(&warehouse, warehouse.items[warehouse.id].item_name);
                break;
            case 3:
                printf("Enter item name: ");
                scanf("%s", warehouse.items[warehouse.id].item_name);
                printf("Enter quantity: ");
                scanf("%d", &warehouse.items[warehouse.id].quantity);
                update_item(&warehouse, warehouse.items[warehouse.id].item_name, warehouse.items[warehouse.id].quantity);
                break;
            case 4:
                print_inventory(&warehouse);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}