//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products in the inventory
#define MAX_PRODUCTS 100

// Define the structure of a product
typedef struct {
    char name[50];
    int quantity;
    float price;
} product_t;

// Declare the array of products
product_t products[MAX_PRODUCTS];

// Get the number of products in the inventory
int get_num_products() {
    int num_products;
    printf("Enter the number of products in the inventory: ");
    scanf("%d", &num_products);
    return num_products;
}

// Get the details of a product
void get_product_details(product_t *product) {
    printf("Enter the name of the product: ");
    scanf(" %[^\n]", product->name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &product->quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &product->price);
}

// Add a product to the inventory
void add_product(int num_products) {
    for (int i = 0; i < num_products; i++) {
        get_product_details(&products[i]);
    }
}

// Display the inventory
void display_inventory(int num_products) {
    printf("\nInventory:\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| Name | Quantity | Price | Total Value |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("| %-20s | %7d | %6.2f | %10.2f |\n", products[i].name, products[i].quantity, products[i].price, products[i].quantity * products[i].price);
    }
    printf("-------------------------------------------------------------------------------------------------\n");
}

// Search for a product by name
void search_product(int num_products) {
    char name[50];
    printf("Enter the name of the product to search for: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found:\n");
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

// Update the quantity of a product
void update_product(int num_products) {
    char name[50];
    int quantity;
    printf("Enter the name of the product to update: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &quantity);
            products[i].quantity = quantity;
            printf("Product updated.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Delete a product from the inventory
void delete_product(int num_products) {
    char name[50];
    printf("Enter the name of the product to delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j + 1];
            }
            num_products--;
            printf("Product deleted.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Main function
int main() {
    int num_products = get_num_products();
    add_product(num_products);
    display_inventory(num_products);
    search_product(num_products);
    update_product(num_products);
    delete_product(num_products);
    display_inventory(num_products);
    return 0;
}