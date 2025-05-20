//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_WAREHOUSES 10

typedef struct {
    char name[50];
    int id;
    float price;
    int quantity;
} Item;

typedef struct {
    char name[50];
    int id;
    int capacity;
    int current_quantity;
} Warehouse;

void initialize_warehouse(Warehouse* warehouse, int id, int capacity) {
    strcpy(warehouse->name, "Warehouse");
    warehouse->id = id;
    warehouse->capacity = capacity;
    warehouse->current_quantity = 0;
}

void add_item(Item* item, int id, char* name, float price, int quantity) {
    strcpy(item->name, name);
    item->id = id;
    item->price = price;
    item->quantity = quantity;
}

int main() {
    Item items[MAX_ITEMS];
    Warehouse warehouses[MAX_WAREHOUSES];

    int num_items = 0;
    int num_warehouses = 0;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        printf("Enter item %d details:\n", i+1);
        printf("Item ID: ");
        scanf("%d", &items[i].id);
        printf("Item Name: ");
        scanf("%s", items[i].name);
        printf("Item Price: ");
        scanf("%f", &items[i].price);
        printf("Item Quantity: ");
        scanf("%d", &items[i].quantity);
    }

    printf("Enter number of warehouses: ");
    scanf("%d", &num_warehouses);

    for (int i = 0; i < num_warehouses; i++) {
        printf("Enter warehouse %d details:\n", i+1);
        printf("Warehouse ID: ");
        scanf("%d", &warehouses[i].id);
        printf("Warehouse Capacity: ");
        scanf("%d", &warehouses[i].capacity);
    }

    for (int i = 0; i < num_items; i++) {
        for (int j = 0; j < num_warehouses; j++) {
            if (warehouses[j].current_quantity + items[i].quantity <= warehouses[j].capacity) {
                warehouses[j].current_quantity += items[i].quantity;
                printf("Item %d added to Warehouse %d\n", i+1, j+1);
            } else {
                printf("Not enough space in Warehouse %d for Item %d\n", j+1, i+1);
            }
        }
    }

    return 0;
}