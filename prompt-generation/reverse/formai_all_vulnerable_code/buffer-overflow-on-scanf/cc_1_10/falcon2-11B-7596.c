//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    int quantity;
    double price;
} Item;

typedef struct {
    Item items[10];
    int num_items;
} Inventory;

void print_inventory(Inventory* inventory) {
    int i;
    for (i = 0; i < inventory->num_items; i++) {
        printf("Item %d: %s (%d units at $%.2f)\n", i + 1, inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
    }
}

void add_item(Inventory* inventory, int id, char* name, int quantity, double price) {
    Item new_item;
    new_item.id = id;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;
    inventory->items[inventory->num_items] = new_item;
    inventory->num_items++;
}

int main() {
    Inventory inventory;
    inventory.num_items = 0;

    int num_items_to_add;
    printf("How many items do you want to add? ");
    scanf("%d", &num_items_to_add);

    for (int i = 0; i < num_items_to_add; i++) {
        int id, quantity, price;
        char name[20];
        printf("Enter item ID: ");
        scanf("%d", &id);
        printf("Enter item name: ");
        scanf("%s", name);
        printf("Enter item quantity: ");
        scanf("%d", &quantity);
        printf("Enter item price: ");
        scanf("%lf", &price);
        add_item(&inventory, id, name, quantity, price);
    }

    print_inventory(&inventory);

    return 0;
}