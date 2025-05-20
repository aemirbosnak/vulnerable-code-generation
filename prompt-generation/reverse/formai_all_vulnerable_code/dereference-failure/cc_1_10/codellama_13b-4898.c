//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for product inventory
typedef struct {
    int id;
    char name[256];
    int quantity;
    float price;
} Product;

// Define struct for inventory list
typedef struct {
    Product* products;
    int size;
    int capacity;
} Inventory;

// Function to initialize inventory list
void init_inventory(Inventory* inventory, int capacity) {
    inventory->products = (Product*)malloc(capacity * sizeof(Product));
    inventory->size = 0;
    inventory->capacity = capacity;
}

// Function to add product to inventory list
void add_product(Inventory* inventory, Product product) {
    if (inventory->size < inventory->capacity) {
        inventory->products[inventory->size] = product;
        inventory->size++;
    } else {
        printf("Inventory is full, unable to add product\n");
    }
}

// Function to remove product from inventory list
void remove_product(Inventory* inventory, int index) {
    if (index >= 0 && index < inventory->size) {
        inventory->products[index] = inventory->products[inventory->size - 1];
        inventory->size--;
    } else {
        printf("Invalid index, unable to remove product\n");
    }
}

// Function to find product in inventory list
Product* find_product(Inventory* inventory, char* name) {
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            return &inventory->products[i];
        }
    }
    return NULL;
}

// Function to print inventory list
void print_inventory(Inventory* inventory) {
    for (int i = 0; i < inventory->size; i++) {
        printf("%d. %s (%d units, $%.2f each)\n", inventory->products[i].id, inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

int main() {
    Inventory inventory;
    init_inventory(&inventory, 10);

    Product p1 = {1, "Apple", 5, 0.50};
    Product p2 = {2, "Banana", 10, 0.25};
    Product p3 = {3, "Orange", 3, 0.35};

    add_product(&inventory, p1);
    add_product(&inventory, p2);
    add_product(&inventory, p3);

    print_inventory(&inventory);

    Product* p4 = find_product(&inventory, "Orange");
    if (p4 != NULL) {
        printf("Orange found at index %d\n", p4 - inventory.products);
    } else {
        printf("Orange not found in inventory\n");
    }

    remove_product(&inventory, 1);
    print_inventory(&inventory);

    return 0;
}