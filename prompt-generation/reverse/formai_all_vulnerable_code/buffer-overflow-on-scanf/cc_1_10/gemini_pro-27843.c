//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[20];
    int quantity;
    float price;
};

struct warehouse {
    struct item items[MAX_ITEMS];
    int num_items;
};

void add_item(struct warehouse *warehouse, struct item item) {
    if (warehouse->num_items < MAX_ITEMS) {
        warehouse->items[warehouse->num_items++] = item;
    }
}

void remove_item(struct warehouse *warehouse, char *name) {
    int i;

    for (i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i] = warehouse->items[warehouse->num_items - 1];
            warehouse->num_items--;
            break;
        }
    }
}

void print_warehouse(struct warehouse *warehouse) {
    int i;

    for (i = 0; i < warehouse->num_items; i++) {
        printf("%s %d %f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

int main() {
    struct warehouse warehouse;
    struct item item;

    warehouse.num_items = 0;

    while (1) {
        printf("Enter command (add, remove, print, quit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter item name: ");
            scanf("%s", item.name);
            printf("Enter item quantity: ");
            scanf("%d", &item.quantity);
            printf("Enter item price: ");
            scanf("%f", &item.price);
            add_item(&warehouse, item);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter item name: ");
            char name[20];
            scanf("%s", name);
            remove_item(&warehouse, name);
        } else if (strcmp(command, "print") == 0) {
            print_warehouse(&warehouse);
        } else if (strcmp(command, "quit") == 0) {
            break;
        }
    }

    return 0;
}