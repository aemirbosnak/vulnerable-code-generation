//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int quantity;
} Item;

typedef struct {
    Item *items;
    int size;
} Inventory;

Inventory *create_inventory() {
    Inventory *inv = (Inventory *) malloc(sizeof(Inventory));
    inv->items = (Item *) malloc(MAX_SIZE * sizeof(Item));
    inv->size = 0;
    return inv;
}

void add_item(Inventory *inv, char *name, int quantity) {
    if (inv->size >= MAX_SIZE) {
        printf("Inventory is full!\n");
        return;
    }
    Item *item = &inv->items[inv->size];
    item->name = strdup(name);
    item->quantity = quantity;
    inv->size++;
}

void remove_item(Inventory *inv, char *name) {
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->items[i].name, name) == 0) {
            free(inv->items[i].name);
            inv->size--;
            for (int j = i; j < inv->size; j++) {
                inv->items[j] = inv->items[j + 1];
            }
            return;
        }
    }
    printf("Item not found!\n");
}

void print_inventory(Inventory *inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->size; i++) {
        printf("%s - %d\n", inv->items[i].name, inv->items[i].quantity);
    }
}

int main() {
    Inventory *inv = create_inventory();
    add_item(inv, "Apples", 10);
    add_item(inv, "Oranges", 5);
    print_inventory(inv);
    remove_item(inv, "Apples");
    print_inventory(inv);
    free(inv->items);
    free(inv);
    return 0;
}