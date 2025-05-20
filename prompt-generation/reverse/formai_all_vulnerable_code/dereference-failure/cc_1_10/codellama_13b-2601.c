//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: mathematical
// Product Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure for the product inventory
struct Product {
    int id;
    char name[100];
    int quantity;
    float price;
};

// Define the structure for the inventory
struct Inventory {
    int capacity;
    int size;
    struct Product* products;
};

// Function to add a product to the inventory
void addProduct(struct Inventory* inventory, struct Product* product) {
    if (inventory->size == inventory->capacity) {
        inventory->capacity *= 2;
        inventory->products = realloc(inventory->products, inventory->capacity * sizeof(struct Product));
    }
    inventory->products[inventory->size].id = product->id;
    strcpy(inventory->products[inventory->size].name, product->name);
    inventory->products[inventory->size].quantity = product->quantity;
    inventory->products[inventory->size].price = product->price;
    inventory->size++;
}

// Function to remove a product from the inventory
void removeProduct(struct Inventory* inventory, int id) {
    for (int i = 0; i < inventory->size; i++) {
        if (inventory->products[i].id == id) {
            inventory->products[i] = inventory->products[inventory->size - 1];
            inventory->size--;
            break;
        }
    }
}

// Function to update the quantity of a product in the inventory
void updateQuantity(struct Inventory* inventory, int id, int quantity) {
    for (int i = 0; i < inventory->size; i++) {
        if (inventory->products[i].id == id) {
            inventory->products[i].quantity = quantity;
            break;
        }
    }
}

// Function to get the total value of the inventory
float getTotalValue(struct Inventory* inventory) {
    float total = 0;
    for (int i = 0; i < inventory->size; i++) {
        total += inventory->products[i].quantity * inventory->products[i].price;
    }
    return total;
}

// Function to print the inventory
void printInventory(struct Inventory* inventory) {
    for (int i = 0; i < inventory->size; i++) {
        printf("%d - %s (%d units, $%.2f each) = $%.2f\n", inventory->products[i].id, inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price, inventory->products[i].quantity * inventory->products[i].price);
    }
}

// Function to free the memory allocated for the inventory
void freeInventory(struct Inventory* inventory) {
    free(inventory->products);
    free(inventory);
}

// Main function
int main() {
    struct Inventory* inventory = malloc(sizeof(struct Inventory));
    inventory->capacity = 10;
    inventory->size = 0;
    inventory->products = malloc(inventory->capacity * sizeof(struct Product));

    struct Product product1 = {1, "Apple", 5, 2.5};
    struct Product product2 = {2, "Orange", 10, 3.5};
    struct Product product3 = {3, "Banana", 3, 1.5};

    addProduct(inventory, &product1);
    addProduct(inventory, &product2);
    addProduct(inventory, &product3);

    removeProduct(inventory, 2);

    updateQuantity(inventory, 1, 10);

    printf("Total value of inventory: $%.2f\n", getTotalValue(inventory));

    printInventory(inventory);

    freeInventory(inventory);

    return 0;
}