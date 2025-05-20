//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: real-life
// Warehouse Management System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct to store information about a product
typedef struct {
    char name[20];
    int quantity;
    float price;
} Product;

// Define a struct to store information about a warehouse
typedef struct {
    char name[20];
    int capacity;
    int current_stock;
    Product* products;
} Warehouse;

// Define a function to create a new warehouse
Warehouse* create_warehouse(char* name, int capacity) {
    Warehouse* warehouse = (Warehouse*) malloc(sizeof(Warehouse));
    strcpy(warehouse->name, name);
    warehouse->capacity = capacity;
    warehouse->current_stock = 0;
    warehouse->products = (Product*) malloc(capacity * sizeof(Product));
    return warehouse;
}

// Define a function to add a product to a warehouse
void add_product(Warehouse* warehouse, char* name, int quantity, float price) {
    // Check if the warehouse has enough capacity
    if (warehouse->current_stock + quantity > warehouse->capacity) {
        printf("Warehouse is full. Cannot add product.\n");
        return;
    }
    // Add the product to the warehouse
    warehouse->current_stock += quantity;
    strcpy(warehouse->products[warehouse->current_stock - 1].name, name);
    warehouse->products[warehouse->current_stock - 1].quantity = quantity;
    warehouse->products[warehouse->current_stock - 1].price = price;
}

// Define a function to remove a product from a warehouse
void remove_product(Warehouse* warehouse, char* name) {
    // Find the product in the warehouse
    for (int i = 0; i < warehouse->current_stock; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            // Remove the product from the warehouse
            warehouse->current_stock--;
            for (int j = i; j < warehouse->current_stock; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            return;
        }
    }
    printf("Product not found in warehouse.\n");
}

// Define a function to display the products in a warehouse
void display_products(Warehouse* warehouse) {
    for (int i = 0; i < warehouse->current_stock; i++) {
        printf("Product: %s\nQuantity: %d\nPrice: %.2f\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
    }
}

int main() {
    // Create a new warehouse
    Warehouse* warehouse = create_warehouse("ABC Warehouse", 100);

    // Add some products to the warehouse
    add_product(warehouse, "Apple", 10, 5.00);
    add_product(warehouse, "Orange", 20, 6.00);
    add_product(warehouse, "Banana", 30, 7.00);

    // Remove a product from the warehouse
    remove_product(warehouse, "Apple");

    // Display the products in the warehouse
    display_products(warehouse);

    // Free the memory allocated for the warehouse
    free(warehouse->products);
    free(warehouse);

    return 0;
}