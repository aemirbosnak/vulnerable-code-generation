//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char *name;
    int quantity;
    float price;
} product;

int main() {
    // Create an array of products
    product products[] = {
        {"iPhone", 10, 999.99},
        {"iPad", 5, 799.99},
        {"Apple Watch", 15, 399.99},
        {"Macbook", 20, 1299.99},
        {"iMac", 10, 1499.99}
    };

    // Get the number of products
    int num_products = sizeof(products) / sizeof(product);

    // Print the products
    printf("Products:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    // Add a new product
    product new_product = {"Apple Pencil", 50, 99.99};
    products[num_products] = new_product;
    num_products++;

    // Print the products again
    printf("\nProducts after adding a new product:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    // Remove a product
    int product_to_remove = 2; // Index of the product to remove
    for (int i = product_to_remove; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }
    num_products--;

    // Print the products again
    printf("\nProducts after removing a product:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    return 0;
}