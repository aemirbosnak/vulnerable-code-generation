//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000
#define MAX_WAREHOUSES 10

typedef struct {
    char name[50];
    int capacity;
    int items_count;
} Warehouse;

typedef struct {
    char name[50];
    int quantity;
    int price;
} Item;

void initialize_warehouse(Warehouse* warehouse, char* name, int capacity) {
    strcpy(warehouse->name, name);
    warehouse->capacity = capacity;
    warehouse->items_count = 0;
}

void add_item(Item* item, char* name, int quantity, int price) {
    strcpy(item->name, name);
    item->quantity = quantity;
    item->price = price;
}

void display_item(Item* item) {
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: $%d\n", item->price);
}

int main() {
    // Initialize warehouses
    Warehouse warehouses[MAX_WAREHOUSES];
    for (int i = 0; i < MAX_WAREHOUSES; i++) {
        char name[50];
        printf("Enter warehouse name: ");
        scanf("%s", name);
        initialize_warehouse(&warehouses[i], name, 1000);
    }

    // Add items to warehouses
    Item items[MAX_ITEMS];
    int items_count = 0;
    while (items_count < MAX_ITEMS) {
        char name[50];
        int quantity;
        int price;
        printf("Enter item name: ");
        scanf("%s", name);
        printf("Enter item quantity: ");
        scanf("%d", &quantity);
        printf("Enter item price: $");
        scanf("%d", &price);
        add_item(&items[items_count], name, quantity, price);
        items_count++;
    }

    // Distribute items to warehouses
    for (int i = 0; i < items_count; i++) {
        Warehouse* warehouse = &warehouses[i % MAX_WAREHOUSES];
        if (warehouse->items_count < warehouse->capacity) {
            Item* item = &items[i];
            warehouse->items_count++;
            printf("Item '%s' added to warehouse '%s'\n", item->name, warehouse->name);
        } else {
            printf("Warehouse '%s' is full\n", warehouse->name);
        }
    }

    return 0;
}