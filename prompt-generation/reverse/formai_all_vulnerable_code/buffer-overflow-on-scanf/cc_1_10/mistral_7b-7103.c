//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void add_item(Warehouse *warehouse, const char *name, int quantity) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full.\n");
        return;
    }

    strcpy(warehouse->items[warehouse->count].name, name);
    warehouse->items[warehouse->count].quantity = quantity;
    warehouse->count++;
}

int main() {
    Warehouse my_warehouse = {0};

    add_item(&my_warehouse, "Apple", 10);
    add_item(&my_warehouse, "Banana", 20);
    add_item(&my_warehouse, "Orange", 30);

    printf("Current inventory:\n");
    for (int i = 0; i < my_warehouse.count; i++) {
        printf("%s: %d\n", my_warehouse.items[i].name, my_warehouse.items[i].quantity);
    }

    int search_index;
    char search_name[MAX_NAME_LEN];

    printf("\nEnter item name to search for: ");
    scanf("%s", search_name);

    for (int i = 0; i < my_warehouse.count; i++) {
        if (strcmp(my_warehouse.items[i].name, search_name) == 0) {
            search_index = i;
            break;
        }
    }

    if (search_index == -1) {
        printf("Item not found.\n");
    } else {
        printf("Item found: %s\n", my_warehouse.items[search_index].name);
        printf("Current quantity: %d\n", my_warehouse.items[search_index].quantity);
    }

    return 0;
}