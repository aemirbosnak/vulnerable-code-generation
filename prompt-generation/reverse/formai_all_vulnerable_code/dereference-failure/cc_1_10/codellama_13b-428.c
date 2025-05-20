//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: scalable
// product_inventory.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the product struct
typedef struct product {
    char* name;
    int quantity;
    double price;
} Product;

// Define the inventory struct
typedef struct inventory {
    Product* products;
    int num_products;
} Inventory;

// Define the functions
void init_inventory(Inventory* inventory) {
    inventory->products = NULL;
    inventory->num_products = 0;
}

void add_product(Inventory* inventory, Product product) {
    // Reallocate the products array
    inventory->products = realloc(inventory->products, (inventory->num_products + 1) * sizeof(Product));
    // Add the new product to the end of the array
    inventory->products[inventory->num_products] = product;
    // Increment the number of products
    inventory->num_products++;
}

void remove_product(Inventory* inventory, int index) {
    // Check if the index is valid
    if (index >= inventory->num_products) {
        printf("Invalid index\n");
        return;
    }
    // Move the products after the removed product to the left
    for (int i = index; i < inventory->num_products - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }
    // Decrement the number of products
    inventory->num_products--;
}

void update_quantity(Inventory* inventory, int index, int quantity) {
    // Check if the index is valid
    if (index >= inventory->num_products) {
        printf("Invalid index\n");
        return;
    }
    // Update the quantity
    inventory->products[index].quantity = quantity;
}

void update_price(Inventory* inventory, int index, double price) {
    // Check if the index is valid
    if (index >= inventory->num_products) {
        printf("Invalid index\n");
        return;
    }
    // Update the price
    inventory->products[index].price = price;
}

void print_inventory(Inventory* inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->num_products; i++) {
        printf("%s: %d %s, $%f\n", inventory->products[i].name, inventory->products[i].quantity, "units", inventory->products[i].price);
    }
}

int main() {
    // Initialize the inventory
    Inventory inventory;
    init_inventory(&inventory);

    // Add some products to the inventory
    Product product1 = {"Apple", 10, 0.5};
    add_product(&inventory, product1);

    Product product2 = {"Banana", 5, 0.3};
    add_product(&inventory, product2);

    // Remove the banana
    remove_product(&inventory, 1);

    // Update the quantity of the apple
    update_quantity(&inventory, 0, 15);

    // Update the price of the apple
    update_price(&inventory, 0, 0.7);

    // Print the inventory
    print_inventory(&inventory);

    return 0;
}