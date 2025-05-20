//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
#define INITIAL_CAPACITY 10

struct warehouse {
    char name[MAX_SIZE];
    int capacity;
    int current_stock;
};

struct item {
    char name[MAX_SIZE];
    int quantity;
    float price;
};

void add_item(struct warehouse *warehouse, struct item *item) {
    if(warehouse->current_stock + item->quantity > warehouse->capacity) {
        printf("Error: Insufficient space in warehouse to add item.\n");
        return;
    }
    warehouse->current_stock += item->quantity;
    printf("Item added successfully.\n");
}

void remove_item(struct warehouse *warehouse, struct item *item) {
    if(warehouse->current_stock < item->quantity) {
        printf("Error: Insufficient quantity of item in warehouse to remove.\n");
        return;
    }
    warehouse->current_stock -= item->quantity;
    printf("Item removed successfully.\n");
}

void display_warehouse_info(struct warehouse *warehouse) {
    printf("Warehouse Name: %s\n", warehouse->name);
    printf("Capacity: %d units\n", warehouse->capacity);
    printf("Current Stock: %d units\n", warehouse->current_stock);
}

void display_item_info(struct item *item) {
    printf("Item Name: %s\n", item->name);
    printf("Quantity: %d units\n", item->quantity);
    printf("Price: $%.2f\n", item->price);
}

int main() {
    struct warehouse warehouse = {0};
    struct item item = {0};

    printf("Enter warehouse name: ");
    scanf("%s", warehouse.name);

    printf("Enter warehouse capacity: ");
    scanf("%d", &warehouse.capacity);

    printf("Enter item name: ");
    scanf("%s", item.name);

    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter item price: ");
    scanf("%f", &item.price);

    add_item(&warehouse, &item);
    display_warehouse_info(&warehouse);

    remove_item(&warehouse, &item);
    display_warehouse_info(&warehouse);

    return 0;
}