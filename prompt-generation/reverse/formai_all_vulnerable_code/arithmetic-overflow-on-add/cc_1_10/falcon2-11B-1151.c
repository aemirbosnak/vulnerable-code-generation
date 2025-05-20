//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_ITEMS 100

typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

typedef struct inventory {
    Product products[MAX_PRODUCTS];
    int items[MAX_ITEMS];
    int total_value;
} Inventory;

void add_product(Inventory* inventory, int id, char* name, float price, int quantity) {
    if (inventory->items[id] > 0) {
        inventory->products[id].quantity += quantity;
        inventory->total_value += (inventory->products[id].price * quantity);
    } else {
        printf("Error: Product %d is already sold out!\n", id);
    }
}

void remove_product(Inventory* inventory, int id) {
    if (inventory->products[id].quantity > 0) {
        inventory->products[id].quantity -= 1;
        inventory->total_value -= (inventory->products[id].price * (inventory->products[id].quantity - 1));
    } else {
        printf("Error: Product %d is already sold out!\n", id);
    }
}

void print_inventory(Inventory* inventory) {
    printf("Product\tQuantity\tTotal Value\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%s\t%d\t%f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price * inventory->products[i].quantity);
    }
    printf("\nTotal Value: %f\n", inventory->total_value);
}

int main() {
    Inventory inventory;
    inventory.total_value = 0;
    inventory.items[0] = 100;

    add_product(&inventory, 1, "Apple", 0.5, 100);
    add_product(&inventory, 2, "Banana", 0.3, 50);
    add_product(&inventory, 3, "Orange", 0.4, 75);

    print_inventory(&inventory);

    remove_product(&inventory, 1);

    print_inventory(&inventory);

    return 0;
}