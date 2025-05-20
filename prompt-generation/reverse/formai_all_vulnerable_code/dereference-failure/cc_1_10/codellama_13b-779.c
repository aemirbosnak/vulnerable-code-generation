//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: rigorous
// product_inventory.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct {
    char name[256];
    int price;
    int quantity;
} Product;

// Define the inventory structure
typedef struct {
    int size;
    Product *products;
} Inventory;

// Initialize the inventory structure
Inventory inventory;

// Function to add a product to the inventory
void add_product(Product product) {
    // Check if the inventory is full
    if (inventory.size == 100) {
        printf("Inventory is full\n");
        return;
    }

    // Add the product to the inventory
    inventory.products[inventory.size] = product;
    inventory.size++;
}

// Function to remove a product from the inventory
void remove_product(int index) {
    // Check if the index is valid
    if (index < 0 || index >= inventory.size) {
        printf("Invalid index\n");
        return;
    }

    // Remove the product from the inventory
    for (int i = index; i < inventory.size - 1; i++) {
        inventory.products[i] = inventory.products[i + 1];
    }
    inventory.size--;
}

// Function to display the inventory
void display_inventory() {
    // Check if the inventory is empty
    if (inventory.size == 0) {
        printf("Inventory is empty\n");
        return;
    }

    // Display the inventory
    for (int i = 0; i < inventory.size; i++) {
        printf("%d: %s - %d\n", i, inventory.products[i].name, inventory.products[i].price);
    }
}

int main() {
    // Add some products to the inventory
    Product product1 = { "Apple", 10, 100 };
    Product product2 = { "Orange", 15, 50 };
    Product product3 = { "Banana", 20, 75 };
    add_product(product1);
    add_product(product2);
    add_product(product3);

    // Remove a product from the inventory
    remove_product(0);

    // Display the inventory
    display_inventory();

    return 0;
}