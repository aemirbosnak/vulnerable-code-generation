//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product information
typedef struct product {
    char name[50];
    int quantity;
    float price;
} product_t;

// Function to add a new product to the inventory
void add_product(product_t *inventory, int *num_products) {
    // Get product details from user
    printf("Enter product name: ");
    scanf("%s", inventory[*num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[*num_products].price);

    // Increment the number of products in the inventory
    (*num_products)++;
}

// Function to search for a product in the inventory
product_t *search_product(product_t *inventory, int num_products, char *name) {
    // Iterate over the inventory to find the product
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Return the product if found
            return &inventory[i];
        }
    }

    // Return NULL if product not found
    return NULL;
}

// Function to update the quantity of a product in the inventory
void update_quantity(product_t *inventory, int num_products, char *name, int quantity) {
    // Find the product in the inventory
    product_t *product = search_product(inventory, num_products, name);

    // If product not found, return
    if (product == NULL) {
        printf("Product not found!\n");
        return;
    }

    // Update the quantity of the product
    product->quantity = quantity;
}

// Function to print the inventory
void print_inventory(product_t *inventory, int num_products) {
    // Iterate over the inventory and print product details
    for (int i = 0; i < num_products; i++) {
        printf("Product: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n\n", inventory[i].price);
    }
}

// Main function
int main() {
    // Initialize the inventory with a maximum of 100 products
    product_t inventory[100];
    int num_products = 0;

    // Main menu loop
    int choice;
    do {
        // Display menu options
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add a new product\n");
        printf("2. Search for a product\n");
        printf("3. Update product quantity\n");
        printf("4. Print the inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1: // Add a new product
                add_product(inventory, &num_products);
                break;
            case 2: // Search for a product
                printf("Enter product name: ");
                char name[50];
                scanf("%s", name);
                product_t *product = search_product(inventory, num_products, name);
                if (product != NULL) {
                    printf("Product found!\n");
                    printf("Name: %s\n", product->name);
                    printf("Quantity: %d\n", product->quantity);
                    printf("Price: %.2f\n", product->price);
                } else {
                    printf("Product not found!\n");
                }
                break;
            case 3: // Update product quantity
                printf("Enter product name: ");
                char name2[50];
                scanf("%s", name2);
                printf("Enter new quantity: ");
                int quantity;
                scanf("%d", &quantity);
                update_quantity(inventory, num_products, name2, quantity);
                break;
            case 4: // Print the inventory
                print_inventory(inventory, num_products);
                break;
            case 5: // Exit the program
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}