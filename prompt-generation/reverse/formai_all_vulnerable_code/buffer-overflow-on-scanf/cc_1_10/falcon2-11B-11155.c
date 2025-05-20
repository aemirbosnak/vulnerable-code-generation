//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int quantity;
} Item;

typedef struct {
    Item items[100];
    int num_items;
} Warehouse;

void add_item(Warehouse* warehouse, Item item) {
    if (warehouse->num_items == 100) {
        fprintf(stderr, "Error: The warehouse is full.\n");
        return;
    }
    warehouse->items[warehouse->num_items].name = item.name;
    warehouse->items[warehouse->num_items].quantity = item.quantity;
    warehouse->num_items++;
}

void remove_item(Warehouse* warehouse, char* name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->num_items - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->num_items--;
            return;
        }
    }
    fprintf(stderr, "Error: Item not found in the warehouse.\n");
}

void list_items(Warehouse* warehouse) {
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("Item: %s\nQuantity: %d\n\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    Warehouse warehouse;
    warehouse.num_items = 0;

    while (1) {
        printf("1. Add item\n2. Remove item\n3. List items\n4. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Item item;
                printf("Enter item name: ");
                scanf("%s", item.name);
                printf("Enter quantity: ");
                scanf("%d", &item.quantity);
                add_item(&warehouse, item);
                break;
            }
            case 2: {
                char name[100];
                printf("Enter item name: ");
                scanf("%s", name);
                remove_item(&warehouse, name);
                break;
            }
            case 3: {
                list_items(&warehouse);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                fprintf(stderr, "Invalid choice.\n");
            }
        }
    }
}