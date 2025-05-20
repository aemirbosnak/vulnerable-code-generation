//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a product
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Create an array of products
Product products[MAX_PRODUCTS];

// Get the number of products
int get_num_products() {
    int num_products;
    printf("Enter the number of products: ");
    scanf("%d", &num_products);
    return num_products;
}

// Get the details of a product
void get_product_details(Product *product) {
    printf("Enter the product ID: ");
    scanf("%d", &product->id);
    printf("Enter the product name: ");
    scanf("%s", product->name);
    printf("Enter the product quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter the product price: ");
    scanf("%f", &product->price);
}

// Add a product to the array
void add_product(Product product) {
    // Find the first empty slot in the array
    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id == 0) {
            // Found an empty slot, add the product
            products[i] = product;
            break;
        }
    }
}

// Search for a product by ID
Product* search_product(int id) {
    // Iterate over the array and search for the product
    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id == id) {
            // Found the product, return it
            return &products[i];
        }
    }

    // Product not found, return NULL
    return NULL;
}

// Update a product
void update_product(Product *product) {
    // Get the new details of the product
    printf("Enter the new product quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter the new product price: ");
    scanf("%f", &product->price);
}

// Delete a product
void delete_product(int id) {
    // Find the product in the array
    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id == id) {
            // Found the product, delete it
            products[i].id = 0;
            break;
        }
    }
}

// Print the product details
void print_product(Product product) {
    printf("Product ID: %d\n", product.id);
    printf("Product Name: %s\n", product.name);
    printf("Product Quantity: %d\n", product.quantity);
    printf("Product Price: %.2f\n", product.price);
}

// Print the list of products
void print_products() {
    int i;
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].id != 0) {
            // Found a product, print it
            print_product(products[i]);
        }
    }
}

// Main function
int main() {
    int num_products = get_num_products();

    // Get the details of each product
    int i;
    for (i = 0; i < num_products; i++) {
        get_product_details(&products[i]);
    }

    // Add the products to the array
    for (i = 0; i < num_products; i++) {
        add_product(products[i]);
    }

    // Print the list of products
    print_products();

    return 0;
}