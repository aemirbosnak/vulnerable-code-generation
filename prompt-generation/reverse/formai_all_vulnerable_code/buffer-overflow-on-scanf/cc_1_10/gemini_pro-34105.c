//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

// Function to add a product to the inventory
void add_product(product *inventory, int *num_products) {
    // Get product details from the user
    printf("Enter product ID: ");
    scanf("%d", &inventory[*num_products].id);

    printf("Enter product name: ");
    scanf(" %[^\n]", inventory[*num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[*num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &inventory[*num_products].price);

    // Increment the number of products
    (*num_products)++;
}

// Function to delete a product from the inventory
void delete_product(product *inventory, int *num_products) {
    // Get product ID from the user
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < *num_products; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    // If the product is found, delete it
    if (index != -1) {
        for (int i = index; i < *num_products - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*num_products)--;
    } else {
        printf("Product not found.\n");
    }
}

// Function to search for a product in the inventory
void search_product(product *inventory, int num_products) {
    // Get product ID from the user
    int id;
    printf("Enter product ID to search for: ");
    scanf("%d", &id);

    // Find the product in the inventory
    int index = -1;
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    // If the product is found, print its details
    if (index != -1) {
        printf("Product found:\n");
        printf("ID: %d\n", inventory[index].id);
        printf("Name: %s\n", inventory[index].name);
        printf("Quantity: %d\n", inventory[index].quantity);
        printf("Price: %.2f\n", inventory[index].price);
    } else {
        printf("Product not found.\n");
    }
}

// Function to print the inventory
void print_inventory(product *inventory, int num_products) {
    printf("Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t\t%d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Main function
int main() {
    // Create an inventory of products
    product inventory[100];
    int num_products = 0;

    // Add some products to the inventory
    add_product(inventory, &num_products);
    add_product(inventory, &num_products);
    add_product(inventory, &num_products);

    // Print the inventory
    print_inventory(inventory, num_products);

    // Delete a product from the inventory
    delete_product(inventory, &num_products);

    // Print the updated inventory
    print_inventory(inventory, num_products);

    // Search for a product in the inventory
    search_product(inventory, num_products);

    return 0;
}