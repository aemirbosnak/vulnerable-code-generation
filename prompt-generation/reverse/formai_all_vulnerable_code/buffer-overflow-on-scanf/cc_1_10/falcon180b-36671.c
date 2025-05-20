//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

struct item {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
};

void add_item(struct item* inventory, int num_items) {
    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);
    printf("Enter item price: ");
    scanf("%f", &inventory[num_items].price);
}

void display_item(struct item item) {
    printf("Item name: %s\n", item.name);
    printf("Item quantity: %d\n", item.quantity);
    printf("Item price: %.2f\n\n", item.price);
}

void display_inventory(struct item* inventory, int num_items) {
    printf("Inventory:\n");
    for (int i = 0; i < num_items; i++) {
        display_item(inventory[i]);
    }
}

int main() {
    struct item inventory[MAX_ITEMS];
    int num_items = 0;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    if (num_items > MAX_ITEMS) {
        printf("Error: Maximum number of items is %d.\n", MAX_ITEMS);
        return 1;
    }

    for (int i = 0; i < num_items; i++) {
        add_item(inventory, i);
    }

    display_inventory(inventory, num_items);

    return 0;
}