//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_QUANTITY 1000

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_WAREHOUSE_SIZE];
    int num_items;
} Warehouse;

Warehouse* create_warehouse() {
    Warehouse* w = malloc(sizeof(Warehouse));
    w->num_items = 0;
    return w;
}

void destroy_warehouse(Warehouse* w) {
    free(w);
}

int add_item(Warehouse* w, char* name, int quantity) {
    if (w->num_items >= MAX_WAREHOUSE_SIZE) {
        printf("Warehouse is full.\n");
        return -1;
    }

    Item* i = &w->items[w->num_items];
    strcpy(i->name, name);
    i->quantity = quantity;
    w->num_items++;

    return 0;
}

int remove_item(Warehouse* w, char* name) {
    int index = -1;
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found.\n");
        return -1;
    }

    w->num_items--;
    for (int i = index; i < w->num_items; i++) {
        w->items[i] = w->items[i+1];
    }

    return 0;
}

int get_item_quantity(Warehouse* w, char* name) {
    int index = -1;
    for (int i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found.\n");
        return -1;
    }

    return w->items[index].quantity;
}

int main() {
    Warehouse* w = create_warehouse();
    add_item(w, "Apples", 100);
    add_item(w, "Oranges", 200);
    add_item(w, "Bananas", 300);

    int quantity = get_item_quantity(w, "Apples");
    printf("Quantity of apples: %d\n", quantity);

    remove_item(w, "Bananas");

    quantity = get_item_quantity(w, "Bananas");
    printf("Quantity of bananas: %d\n", quantity);

    destroy_warehouse(w);
    return 0;
}