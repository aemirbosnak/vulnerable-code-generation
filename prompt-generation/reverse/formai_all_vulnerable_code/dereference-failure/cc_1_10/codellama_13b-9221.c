//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Inventory structure
struct Inventory {
    int id;
    struct Product* products;
    int num_products;
};

// Function to add a product to an inventory
void addProduct(struct Inventory* inv, struct Product* product) {
    inv->products[inv->num_products] = *product;
    inv->num_products++;
}

// Function to remove a product from an inventory
void removeProduct(struct Inventory* inv, int id) {
    for (int i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            inv->num_products--;
            for (int j = i; j < inv->num_products; j++) {
                inv->products[j] = inv->products[j + 1];
            }
            break;
        }
    }
}

// Function to display the inventory
void displayInventory(struct Inventory* inv) {
    for (int i = 0; i < inv->num_products; i++) {
        printf("Product %d: %s, $%.2f, %d units\n", inv->products[i].id, inv->products[i].name, inv->products[i].price, inv->products[i].quantity);
    }
}

int main() {
    // Create a new inventory
    struct Inventory inv = {0, NULL, 0};

    // Add some products to the inventory
    struct Product prod1 = {1, "Apple", 1.5, 10};
    struct Product prod2 = {2, "Banana", 2.5, 5};
    struct Product prod3 = {3, "Orange", 3.5, 3};
    addProduct(&inv, &prod1);
    addProduct(&inv, &prod2);
    addProduct(&inv, &prod3);

    // Remove a product from the inventory
    removeProduct(&inv, 2);

    // Display the inventory
    displayInventory(&inv);

    return 0;
}