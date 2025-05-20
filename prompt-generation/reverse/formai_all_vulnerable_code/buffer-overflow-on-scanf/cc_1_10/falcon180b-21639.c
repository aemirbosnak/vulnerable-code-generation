//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define MAX_ITEMS 50
#define MAX_NAME_SIZE 50
#define MAX_QUANTITY 1000

typedef struct item {
    char name[MAX_NAME_SIZE];
    int quantity;
} item_t;

typedef struct warehouse {
    item_t items[MAX_ITEMS];
    int num_items;
} warehouse_t;

void init_warehouse(warehouse_t *warehouse) {
    warehouse->num_items = 0;
}

void add_item(warehouse_t *warehouse, char *name, int quantity) {
    if (warehouse->num_items >= MAX_ITEMS) {
        printf("Error: Warehouse is full.\n");
        return;
    }

    item_t item;
    strcpy(item.name, name);
    item.quantity = quantity;

    warehouse->items[warehouse->num_items++] = item;
}

void remove_item(warehouse_t *warehouse, char *name) {
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->num_items--;
            for (int j = i; j < warehouse->num_items; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            return;
        }
    }

    printf("Error: Item not found.\n");
}

void display_items(warehouse_t *warehouse) {
    printf("Items in warehouse:\n");
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s: %d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
}

int main() {
    warehouse_t warehouse;
    init_warehouse(&warehouse);

    char name[MAX_NAME_SIZE];
    int quantity;

    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. Display items\n4. Exit\n");
        scanf("%d", &quantity);

        switch (quantity) {
            case 1:
                printf("Enter name of item: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(&warehouse, name, quantity);
                break;

            case 2:
                printf("Enter name of item to remove: ");
                scanf("%s", name);
                remove_item(&warehouse, name);
                break;

            case 3:
                display_items(&warehouse);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}