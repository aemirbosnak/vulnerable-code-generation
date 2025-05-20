//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product details
typedef struct product {
    int product_id;
    char product_name[50];
    int quantity;
    float price;
} product;

// Function to add a new product to the warehouse
void add_product(product *products, int *num_products) {
    // Get the product details from the user
    printf("Enter product ID: ");
    scanf("%d", &products[*num_products].product_id);
    printf("Enter product name: ");
    scanf(" %[^\n]s", products[*num_products].product_name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*num_products].price);

    // Increment the number of products
    (*num_products)++;
}

// Function to search for a product by its ID
product *search_product(product *products, int num_products, int product_id) {
    for (int i = 0; i < num_products; i++) {
        if (products[i].product_id == product_id) {
            return &products[i];
        }
    }

    return NULL;
}

// Function to update the quantity of a product
void update_product(product *products, int num_products, int product_id, int new_quantity) {
    // Search for the product by its ID
    product *product_ptr = search_product(products, num_products, product_id);

    // If the product is found, update its quantity
    if (product_ptr != NULL) {
        product_ptr->quantity = new_quantity;
    }
}

// Function to delete a product from the warehouse
void delete_product(product *products, int *num_products, int product_id) {
    // Search for the product by its ID
    product *product_ptr = search_product(products, *num_products, product_id);

    // If the product is found, delete it
    if (product_ptr != NULL) {
        // Shift the remaining products to the left
        for (int i = product_ptr - products; i < *num_products - 1; i++) {
            products[i] = products[i + 1];
        }

        // Decrement the number of products
        (*num_products)--;
    }
}

// Function to print the details of all products in the warehouse
void print_products(product *products, int num_products) {
    printf("\n\nProduct Details:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| Product ID | Product Name | Quantity | Price |\n");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("| %9d | %20s | %8d | %7.2f |\n",
               products[i].product_id, products[i].product_name, products[i].quantity, products[i].price);
    }
    printf("-----------------------------------------------------------------------------\n");
}

// Main function
int main() {
    // Create an array of products
    product products[100];

    // Initialize the number of products to 0
    int num_products = 0;

    // Add some products to the warehouse
    add_product(products, &num_products);
    add_product(products, &num_products);
    add_product(products, &num_products);

    // Print the details of all products in the warehouse
    print_products(products, num_products);

    // Search for a product by its ID
    int product_id;
    printf("\nEnter product ID to search for: ");
    scanf("%d", &product_id);
    product *product_ptr = search_product(products, num_products, product_id);

    // If the product is found, print its details
    if (product_ptr != NULL) {
        printf("\nProduct Details:\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("| Product ID | Product Name | Quantity | Price |\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("| %9d | %20s | %8d | %7.2f |\n",
               product_ptr->product_id, product_ptr->product_name, product_ptr->quantity, product_ptr->price);
        printf("-----------------------------------------------------------------------------\n");
    } else {
        printf("\nProduct not found.\n");
    }

    // Update the quantity of a product
    int new_quantity;
    printf("\nEnter product ID to update quantity for: ");
    scanf("%d", &product_id);
    printf("Enter new quantity: ");
    scanf("%d", &new_quantity);
    update_product(products, num_products, product_id, new_quantity);

    // Print the details of all products in the warehouse
    print_products(products, num_products);

    // Delete a product from the warehouse
    printf("\nEnter product ID to delete: ");
    scanf("%d", &product_id);
    delete_product(products, &num_products, product_id);

    // Print the details of all products in the warehouse
    print_products(products, num_products);

    return 0;
}