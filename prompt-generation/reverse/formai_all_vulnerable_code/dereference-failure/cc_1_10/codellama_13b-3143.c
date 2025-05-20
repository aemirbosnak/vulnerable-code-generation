//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
/*
 * A medieval-style warehouse management system
 *
 * Written in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structs for the products and inventory
struct product {
    char name[50];
    int quantity;
    float price;
};

struct inventory {
    struct product* products[100];
    int num_products;
};

// Function to add a product to the inventory
void add_product(struct inventory* inv, struct product* p) {
    inv->products[inv->num_products] = p;
    inv->num_products++;
}

// Function to retrieve a product from the inventory
struct product* get_product(struct inventory* inv, int index) {
    return inv->products[index];
}

// Function to print the inventory
void print_inventory(struct inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->num_products; i++) {
        struct product* p = inv->products[i];
        printf("%s (%d): $%.2f\n", p->name, p->quantity, p->price);
    }
}

// Main function
int main() {
    // Create an inventory struct
    struct inventory inv;
    inv.num_products = 0;

    // Add some products to the inventory
    struct product* p1 = malloc(sizeof(struct product));
    strcpy(p1->name, "Sword");
    p1->quantity = 10;
    p1->price = 50.00;
    add_product(&inv, p1);

    struct product* p2 = malloc(sizeof(struct product));
    strcpy(p2->name, "Shield");
    p2->quantity = 5;
    p2->price = 30.00;
    add_product(&inv, p2);

    struct product* p3 = malloc(sizeof(struct product));
    strcpy(p3->name, "Armor");
    p3->quantity = 3;
    p3->price = 80.00;
    add_product(&inv, p3);

    // Print the inventory
    print_inventory(&inv);

    // Retrieve a product from the inventory
    struct product* p4 = get_product(&inv, 0);
    printf("Product: %s\n", p4->name);

    return 0;
}