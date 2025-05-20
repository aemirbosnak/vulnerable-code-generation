//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products in the inventory

// Product structure
typedef struct {
    char name[50];
    int id;
    float price;
    int quantity;
} Product;

// Inventory structure
typedef struct {
    Product products[MAX_PRODUCTS];
    int num_products;
} Inventory;

/* Function declarations */
void add_product(Inventory* inventory);
void remove_product(Inventory* inventory);
void print_inventory(Inventory* inventory);

/* Main function */
int main() {
    Inventory inventory;
    inventory.num_products = 0;
    int option;

    do {
        printf("\n\n\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Print inventory\n");
        printf("4. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: // Add product
                add_product(&inventory);
                break;
            case 2: // Remove product
                remove_product(&inventory);
                break;
            case 3: // Print inventory
                print_inventory(&inventory);
                break;
            case 4: // Exit
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 4);

    return 0;
}

/* Function definitions */

// Add product to inventory
void add_product(Inventory* inventory) {
    // Check if maximum number of products has been reached
    if (inventory->num_products == MAX_PRODUCTS) {
        printf("Cannot add product, maximum number of products reached!\n");
        return;
    }

    // Get product details from user
    Product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product ID: ");
    scanf("%d", &product.id);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);

    // Add product to inventory
    inventory->products[inventory->num_products++] = product;

    printf("Product added to inventory!\n");
}

// Remove product from inventory
void remove_product(Inventory* inventory) {
    // Check if inventory is empty
    if (inventory->num_products == 0) {
        printf("Inventory is empty, cannot remove product!\n");
        return;
    }

    // Get product ID from user
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    // Find product with given ID
    int index = -1;
    for (int i = 0; i < inventory->num_products; i++) {
        if (inventory->products[i].id == id) {
            index = i;
            break;
        }
    }

    // Remove product from inventory
    if (index == -1) {
        printf("Product not found in inventory!\n");
    } else {
        for (int i = index; i < inventory->num_products - 1; i++) {
            inventory->products[i] = inventory->products[i+1];
        }
        inventory->num_products--;
        printf("Product removed from inventory!\n");
    }
}

// Print inventory
void print_inventory(Inventory* inventory) {
    // Check if inventory is empty
    if (inventory->num_products == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\n\n\nInventory\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("%-20s %10s %15s %15s\n", "Product Name", "ID", "Price", "Quantity");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < inventory->num_products; i++) {
        printf("%-20s %10d %15.2f %15d\n", inventory->products[i].name, inventory->products[i].id,
               inventory->products[i].price, inventory->products[i].quantity);
    }
    printf("--------------------------------------------------------------------------------\n");
}