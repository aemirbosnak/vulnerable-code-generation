//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: real-life
// Warehouse Management System in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct to represent a product
struct Product {
    char name[20];
    int quantity;
    float price;
};

// Define a struct to represent a warehouse
struct Warehouse {
    char name[20];
    struct Product* products[10];
    int num_products;
};

// Function to add a product to a warehouse
void addProduct(struct Warehouse* warehouse, struct Product* product) {
    warehouse->products[warehouse->num_products] = product;
    warehouse->num_products++;
}

// Function to remove a product from a warehouse
void removeProduct(struct Warehouse* warehouse, char* product_name) {
    for (int i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i]->name, product_name) == 0) {
            warehouse->products[i] = NULL;
            warehouse->num_products--;
            break;
        }
    }
}

// Function to print the products in a warehouse
void printProducts(struct Warehouse* warehouse) {
    for (int i = 0; i < warehouse->num_products; i++) {
        printf("%s - %d - %f\n", warehouse->products[i]->name, warehouse->products[i]->quantity, warehouse->products[i]->price);
    }
}

int main() {
    // Create a warehouse
    struct Warehouse* warehouse = malloc(sizeof(struct Warehouse));
    strcpy(warehouse->name, "ABC Warehouse");
    warehouse->num_products = 0;

    // Create some products
    struct Product* product1 = malloc(sizeof(struct Product));
    strcpy(product1->name, "Apple");
    product1->quantity = 100;
    product1->price = 0.5;

    struct Product* product2 = malloc(sizeof(struct Product));
    strcpy(product2->name, "Orange");
    product2->quantity = 50;
    product2->price = 0.25;

    struct Product* product3 = malloc(sizeof(struct Product));
    strcpy(product3->name, "Banana");
    product3->quantity = 20;
    product3->price = 0.15;

    // Add the products to the warehouse
    addProduct(warehouse, product1);
    addProduct(warehouse, product2);
    addProduct(warehouse, product3);

    // Print the products in the warehouse
    printProducts(warehouse);

    // Remove a product from the warehouse
    removeProduct(warehouse, "Apple");

    // Print the products in the warehouse again
    printProducts(warehouse);

    // Free the memory allocated for the warehouse and products
    free(warehouse);
    free(product1);
    free(product2);
    free(product3);

    return 0;
}