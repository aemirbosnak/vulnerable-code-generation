//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
// Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Inventory {
    int num_products;
    struct Product* products;
};

struct Inventory* create_inventory() {
    struct Inventory* inv = malloc(sizeof(struct Inventory));
    inv->num_products = 0;
    inv->products = NULL;
    return inv;
}

void add_product(struct Inventory* inv, struct Product* product) {
    inv->products = realloc(inv->products, (inv->num_products + 1) * sizeof(struct Product));
    inv->products[inv->num_products] = *product;
    inv->num_products++;
}

void remove_product(struct Inventory* inv, int id) {
    for (int i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            for (int j = i; j < inv->num_products - 1; j++) {
                inv->products[j] = inv->products[j + 1];
            }
            inv->num_products--;
            break;
        }
    }
}

void print_inventory(struct Inventory* inv) {
    printf("Inventory: \n");
    for (int i = 0; i < inv->num_products; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %f\n", inv->products[i].id, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

int main() {
    struct Inventory* inv = create_inventory();
    struct Product p1 = {1, "Apple", 10, 5.0};
    struct Product p2 = {2, "Banana", 5, 3.5};
    struct Product p3 = {3, "Orange", 15, 4.5};
    add_product(inv, &p1);
    add_product(inv, &p2);
    add_product(inv, &p3);
    print_inventory(inv);
    remove_product(inv, 2);
    print_inventory(inv);
    return 0;
}