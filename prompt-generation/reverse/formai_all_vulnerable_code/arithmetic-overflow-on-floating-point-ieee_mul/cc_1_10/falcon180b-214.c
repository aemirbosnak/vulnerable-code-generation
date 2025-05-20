//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a product
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Define the structure of a warehouse
typedef struct {
    char name[50];
    int capacity;
    Product products[100];
    int num_products;
} Warehouse;

// Function to initialize a warehouse
void init_warehouse(Warehouse *warehouse) {
    warehouse->num_products = 0;
}

// Function to add a product to a warehouse
void add_product(Warehouse *warehouse, Product product) {
    if (warehouse->num_products >= warehouse->capacity) {
        printf("Warehouse is full. Cannot add product.\n");
        return;
    }
    warehouse->products[warehouse->num_products] = product;
    warehouse->num_products++;
}

// Function to remove a product from a warehouse
void remove_product(Warehouse *warehouse, char *name) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        if (strcmp(warehouse->products[i].name, name) == 0) {
            warehouse->num_products--;
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Product not found in warehouse.\n");
}

// Function to display the products in a warehouse
void display_products(Warehouse *warehouse) {
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        printf("Name: %s\n", warehouse->products[i].name);
        printf("Quantity: %d\n", warehouse->products[i].quantity);
        printf("Price: $%.2f\n\n", warehouse->products[i].price);
    }
}

// Function to calculate the total value of products in a warehouse
float calculate_total_value(Warehouse *warehouse) {
    float total_value = 0.0;
    int i;
    for (i = 0; i < warehouse->num_products; i++) {
        total_value += warehouse->products[i].quantity * warehouse->products[i].price;
    }
    return total_value;
}

// Main function
int main() {
    Warehouse warehouse1;
    init_warehouse(&warehouse1);
    add_product(&warehouse1, (Product) {"Apple", 100, 1.00});
    add_product(&warehouse1, (Product) {"Banana", 200, 0.50});
    display_products(&warehouse1);
    printf("Total value of products: $%.2f\n", calculate_total_value(&warehouse1));
    remove_product(&warehouse1, "Banana");
    display_products(&warehouse1);
    printf("Total value of products: $%.2f\n", calculate_total_value(&warehouse1));
    return 0;
}