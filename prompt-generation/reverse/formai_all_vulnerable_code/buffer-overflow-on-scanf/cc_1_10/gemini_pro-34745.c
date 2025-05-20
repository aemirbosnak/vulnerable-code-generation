//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function to add a product to the inventory
void add_product(Product *inventory, int *num_products) {
    // Get product details from user
    printf("Enter product ID: ");
    scanf("%d", &inventory[*num_products].id);
    printf("Enter product name: ");
    scanf("%s", inventory[*num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[*num_products].price);

    // Increment the number of products in the inventory
    *num_products += 1;
}

// Function to search for a product in the inventory by ID
Product *search_product_by_id(Product *inventory, int num_products, int id) {
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            return &inventory[i];
        }
    }

    return NULL;
}

// Function to search for a product in the inventory by name
Product *search_product_by_name(Product *inventory, int num_products, char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return &inventory[i];
        }
    }

    return NULL;
}

// Function to update a product in the inventory
void update_product(Product *inventory, int num_products) {
    // Get product ID from user
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    Product *product = search_product_by_id(inventory, num_products, id);

    // If product is not found, print error message
    if (product == NULL) {
        printf("Product not found!\n");
        return;
    }

    // Get updated product details from user
    printf("Enter updated product name: ");
    scanf("%s", product->name);
    printf("Enter updated product quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter updated product price: ");
    scanf("%f", &product->price);
}

// Function to delete a product from the inventory
void delete_product(Product *inventory, int *num_products) {
    // Get product ID from user
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    // Search for the product in the inventory
    Product *product = search_product_by_id(inventory, *num_products, id);

    // If product is not found, print error message
    if (product == NULL) {
        printf("Product not found!\n");
        return;
    }

    // Shift all products after the deleted product one position to the left
    for (int i = product - inventory; i < *num_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    // Decrement the number of products in the inventory
    *num_products -= 1;
}

// Function to print the inventory
void print_inventory(Product *inventory, int num_products) {
    printf("Product Inventory:\n");
    printf("--------------------\n");
    printf("ID | Name | Quantity | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %d | %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    // Create an array to store the product inventory
    Product inventory[100];

    // Initialize the number of products in the inventory to 0
    int num_products = 0;

    // Add some products to the inventory
    add_product(inventory, &num_products);
    add_product(inventory, &num_products);
    add_product(inventory, &num_products);

    // Print the inventory
    print_inventory(inventory, num_products);

    // Search for a product by ID
    Product *product = search_product_by_id(inventory, num_products, 2);
    if (product != NULL) {
        printf("Product found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n", product->id, product->name, product->quantity, product->price);
    } else {
        printf("Product not found!\n");
    }

    // Search for a product by name
    product = search_product_by_name(inventory, num_products, "Product 2");
    if (product != NULL) {
        printf("Product found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n", product->id, product->name, product->quantity, product->price);
    } else {
        printf("Product not found!\n");
    }

    // Update a product
    update_product(inventory, num_products);

    // Delete a product
    delete_product(inventory, &num_products);

    // Print the updated inventory
    print_inventory(inventory, num_products);

    return 0;
}