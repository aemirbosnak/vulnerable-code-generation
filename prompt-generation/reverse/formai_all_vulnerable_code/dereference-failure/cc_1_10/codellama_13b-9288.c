//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: Sherlock Holmes
/*
 * A unique C Product Inventory System example program in a Sherlock Holmes style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product structure
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Define the inventory structure
typedef struct {
    Product *products;
    int size;
} Inventory;

// Define the inventory functions
void initInventory(Inventory *inv, int size);
void addProduct(Inventory *inv, Product *product);
void removeProduct(Inventory *inv, char *name);
void printInventory(Inventory *inv);

// Implement the inventory functions
void initInventory(Inventory *inv, int size) {
    inv->size = size;
    inv->products = (Product *)malloc(size * sizeof(Product));
}

void addProduct(Inventory *inv, Product *product) {
    // Check if the inventory is full
    if (inv->size == 0) {
        printf("Inventory is full!\n");
        return;
    }

    // Add the product to the inventory
    inv->products[inv->size - 1] = *product;
    inv->size--;
}

void removeProduct(Inventory *inv, char *name) {
    // Check if the product exists in the inventory
    for (int i = 0; i < inv->size; i++) {
        if (strcmp(inv->products[i].name, name) == 0) {
            // Remove the product from the inventory
            for (int j = i; j < inv->size - 1; j++) {
                inv->products[j] = inv->products[j + 1];
            }
            inv->size--;
            return;
        }
    }

    // Product not found
    printf("Product not found in the inventory!\n");
}

void printInventory(Inventory *inv) {
    // Print the inventory
    for (int i = 0; i < inv->size; i++) {
        printf("Product %d: %s (%d, %.2f)\n", i + 1, inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
    }
}

// Main function
int main() {
    // Initialize the inventory
    Inventory inv;
    initInventory(&inv, 10);

    // Add some products to the inventory
    Product product1 = {"Apple", 10, 5.0};
    Product product2 = {"Banana", 5, 3.0};
    Product product3 = {"Orange", 8, 4.0};
    addProduct(&inv, &product1);
    addProduct(&inv, &product2);
    addProduct(&inv, &product3);

    // Remove a product from the inventory
    removeProduct(&inv, "Banana");

    // Print the inventory
    printInventory(&inv);

    return 0;
}