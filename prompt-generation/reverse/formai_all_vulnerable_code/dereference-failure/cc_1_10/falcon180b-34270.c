//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 100
#define MAX_ITEM_NAME_SIZE 50
#define MAX_ITEM_QTY_SIZE 10

typedef struct {
    char name[MAX_ITEM_NAME_SIZE];
    int qty;
    int location;
} Item;

typedef struct {
    char name[MAX_ITEM_NAME_SIZE];
    int qty;
    int location;
} Warehouse;

void initWarehouse(Warehouse* warehouse) {
    for (int i = 0; i < MAX_WAREHOUSE_SIZE; i++) {
        strcpy(warehouse[i].name, "");
        warehouse[i].qty = 0;
        warehouse[i].location = -1;
    }
}

void printWarehouse(Warehouse* warehouse) {
    for (int i = 0; i < MAX_WAREHOUSE_SIZE; i++) {
        if (warehouse[i].qty > 0) {
            printf("Item %s: %d units at location %d\n", warehouse[i].name, warehouse[i].qty, warehouse[i].location);
        }
    }
}

void addItem(Item* item, Warehouse* warehouse) {
    int location = -1;
    for (int i = 0; i < MAX_WAREHOUSE_SIZE; i++) {
        if (warehouse[i].qty == 0) {
            location = i;
            break;
        }
    }
    if (location == -1) {
        printf("No space in the warehouse.\n");
    } else {
        strcpy(warehouse[location].name, item->name);
        warehouse[location].qty = item->qty;
        warehouse[location].location = location;
        item->location = location;
    }
}

void removeItem(int itemId, Warehouse* warehouse) {
    for (int i = 0; i < MAX_WAREHOUSE_SIZE; i++) {
        if (warehouse[i].qty > 0 && warehouse[i].name[0]!= '\0' && strcmp(warehouse[i].name, "") == 0) {
            if (warehouse[i].location == itemId) {
                warehouse[i].qty = 0;
                strcpy(warehouse[i].name, "");
            }
        }
    }
}

int main() {
    Item item1 = {"Apple", 100, -1};
    Item item2 = {"Banana", 50, -1};
    Warehouse warehouse = {{0}};

    initWarehouse(&warehouse);

    addItem(&item1, &warehouse);
    addItem(&item2, &warehouse);

    printWarehouse(&warehouse);

    removeItem(1, &warehouse);

    printWarehouse(&warehouse);

    return 0;
}