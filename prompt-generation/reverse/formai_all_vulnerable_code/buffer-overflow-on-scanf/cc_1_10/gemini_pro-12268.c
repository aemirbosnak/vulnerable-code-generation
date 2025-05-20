//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product details
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Function to add a new product to the inventory
void add_product(product *inventory, int *num_products) {
    // Get the product details from the user
    printf("Enter product ID: ");
    scanf("%d", &inventory[*num_products].id);
    printf("Enter product name: ");
    scanf(" %[^\n]%*c", inventory[*num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[*num_products].price);

    // Increment the number of products in the inventory
    (*num_products)++;
}

// Function to search for a product in the inventory
int search_product(product *inventory, int num_products, int id) {
    // Iterate through the inventory to find the product with the given ID
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }

    // Product not found
    return -1;
}

// Function to update the quantity of a product in the inventory
void update_quantity(product *inventory, int num_products, int id, int quantity) {
    // Search for the product in the inventory
    int index = search_product(inventory, num_products, id);

    // If the product is found, update the quantity
    if (index != -1) {
        inventory[index].quantity = quantity;
    } else {
        printf("Product not found!\n");
    }
}

// Function to delete a product from the inventory
void delete_product(product *inventory, int *num_products, int id) {
    // Search for the product in the inventory
    int index = search_product(inventory, *num_products, id);

    // If the product is found, delete it
    if (index != -1) {
        for (int i = index; i < *num_products - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*num_products)--;
    } else {
        printf("Product not found!\n");
    }
}

// Function to print the inventory
void print_inventory(product *inventory, int num_products) {
    // Print the header
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");

    // Iterate through the inventory and print the product details
    for (int i = 0; i < num_products; i++) {
        printf("%-5d %-20s %-10d %-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Main function
int main() {
    // Create an array to store the products
    product inventory[100];

    // Initialize the number of products to 0
    int num_products = 0;

    // Add some products to the inventory
    add_product(inventory, &num_products);
    add_product(inventory, &num_products);
    add_product(inventory, &num_products);

    // Search for a product in the inventory
    int id = 2;
    int index = search_product(inventory, num_products, id);
    if (index != -1) {
        printf("Product found:\n");
        printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
        printf("%-5d %-20s %-10d %-10.2f\n", inventory[index].id, inventory[index].name, inventory[index].quantity, inventory[index].price);
    } else {
        printf("Product not found!\n");
    }

    // Update the quantity of a product in the inventory
    id = 1;
    int quantity = 50;
    update_quantity(inventory, num_products, id, quantity);

    // Delete a product from the inventory
    id = 3;
    delete_product(inventory, &num_products, id);

    // Print the inventory
    print_inventory(inventory, num_products);

    return 0;
}