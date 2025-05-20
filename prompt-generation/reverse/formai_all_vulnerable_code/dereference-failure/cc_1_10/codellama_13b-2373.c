//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct Product {
    int id;
    char name[256];
    int quantity;
};

struct Inventory {
    int id;
    int capacity;
    struct Product* products;
};

int main() {
    // Create an inventory with a capacity of 10 products
    struct Inventory* inventory = (struct Inventory*)malloc(sizeof(struct Inventory));
    inventory->id = 1;
    inventory->capacity = 10;
    inventory->products = (struct Product*)malloc(sizeof(struct Product) * inventory->capacity);

    // Add some products to the inventory
    struct Product product1;
    product1.id = 1;
    strcpy(product1.name, "Apple");
    product1.quantity = 10;
    inventory->products[0] = product1;

    struct Product product2;
    product2.id = 2;
    strcpy(product2.name, "Orange");
    product2.quantity = 20;
    inventory->products[1] = product2;

    struct Product product3;
    product3.id = 3;
    strcpy(product3.name, "Banana");
    product3.quantity = 30;
    inventory->products[2] = product3;

    // Print the inventory
    printf("Inventory: %d\n", inventory->id);
    for (int i = 0; i < inventory->capacity; i++) {
        struct Product* product = &inventory->products[i];
        printf("Product %d: %s (%d)\n", product->id, product->name, product->quantity);
    }

    // Free the inventory
    free(inventory->products);
    free(inventory);

    return 0;
}