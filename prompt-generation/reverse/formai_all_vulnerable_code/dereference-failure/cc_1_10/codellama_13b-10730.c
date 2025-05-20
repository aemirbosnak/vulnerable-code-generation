//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: active
// Product Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
struct Product {
    char name[50];
    int price;
    int quantity;
};

// Define the inventory structure
struct Inventory {
    struct Product* products;
    int num_products;
};

// Function to add a product to the inventory
void addProduct(struct Inventory* inventory, char* name, int price, int quantity) {
    // Check if the inventory is full
    if (inventory->num_products == 50) {
        printf("Inventory is full, cannot add more products\n");
        return;
    }

    // Create a new product and add it to the inventory
    struct Product* new_product = (struct Product*)malloc(sizeof(struct Product));
    strcpy(new_product->name, name);
    new_product->price = price;
    new_product->quantity = quantity;
    inventory->products[inventory->num_products++] = *new_product;
}

// Function to remove a product from the inventory
void removeProduct(struct Inventory* inventory, char* name) {
    // Find the product in the inventory
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            break;
        }
    }

    // Check if the product was found
    if (i == inventory->num_products) {
        printf("Product not found in inventory\n");
        return;
    }

    // Remove the product from the inventory
    int j;
    for (j = i; j < inventory->num_products - 1; j++) {
        inventory->products[j] = inventory->products[j + 1];
    }
    inventory->num_products--;
}

// Function to display the inventory
void displayInventory(struct Inventory* inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->num_products; i++) {
        printf("%s\n", inventory->products[i].name);
    }
}

// Main function
int main() {
    // Create a new inventory
    struct Inventory* inventory = (struct Inventory*)malloc(sizeof(struct Inventory));
    inventory->num_products = 0;

    // Add some products to the inventory
    addProduct(inventory, "Apple", 5, 10);
    addProduct(inventory, "Orange", 10, 5);
    addProduct(inventory, "Banana", 3, 15);

    // Remove a product from the inventory
    removeProduct(inventory, "Orange");

    // Display the inventory
    displayInventory(inventory);

    // Free the inventory memory
    free(inventory);

    return 0;
}