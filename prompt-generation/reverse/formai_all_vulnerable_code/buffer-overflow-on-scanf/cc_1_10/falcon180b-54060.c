//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSES 10
#define MAX_ITEMS 100
#define MAX_CUSTOMERS 50

struct warehouse {
    char name[50];
    int items[MAX_ITEMS];
    int num_items;
};

struct customer {
    char name[50];
    int id;
};

struct item {
    char name[50];
    int id;
    int quantity;
};

void create_warehouse(struct warehouse *warehouse) {
    printf("Enter warehouse name: ");
    scanf("%s", warehouse->name);
    warehouse->num_items = 0;
}

void add_item(struct warehouse *warehouse, struct item *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);
    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);
    item->id = warehouse->num_items;
    warehouse->items[item->id] = item->quantity;
    warehouse->num_items++;
}

void create_customer(struct customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    customer->id = rand() % 10000;
}

void order_item(struct warehouse *warehouse, struct customer *customer, struct item *item) {
    int i;
    for (i = 0; i < warehouse->num_items; i++) {
        if (warehouse->items[i] == item->quantity) {
            printf("Item %s is in stock. Order placed.\n", item->name);
            warehouse->items[i] -= item->quantity;
            printf("New stock of item %s: %d\n", item->name, warehouse->items[i]);
            break;
        }
    }
}

void main() {
    int i, j;
    struct warehouse warehouse[MAX_WAREHOUSES];
    struct customer customer[MAX_CUSTOMERS];
    struct item item[MAX_ITEMS];

    // Create warehouses
    for (i = 0; i < MAX_WAREHOUSES; i++) {
        create_warehouse(&warehouse[i]);
    }

    // Create customers
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        create_customer(&customer[i]);
    }

    // Create items
    for (i = 0; i < MAX_ITEMS; i++) {
        add_item(&warehouse[0], &item[i]);
    }

    // Place orders
    for (i = 0; i < MAX_CUSTOMERS; i++) {
        printf("Customer %s placing order:\n", customer[i].name);
        for (j = 0; j < MAX_ITEMS; j++) {
            order_item(&warehouse[0], &customer[i], &item[j]);
        }
    }
}