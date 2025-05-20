//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define NAME_LENGTH 20

// Define Product struct
struct Product {
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

// Declare functions
void add_product(struct Product inventory[], int* num_products);
void show_inventory(struct Product inventory[], int num_products);
void update_product(struct Product inventory[], int num_products);
void delete_product(struct Product inventory[], int* num_products);
int find_product(struct Product inventory[], int num_products, char name[]);

int main() {
    struct Product inventory[MAX_ITEMS];  // Declare inventory array
    int num_products = 0;  // Keep track of number of products in inventory
    int choice;  // Keep track of user's menu choice

    // Loop until user chooses to exit program
    while (1) {
        // Display menu
        printf("\n1. Add Product\n");
        printf("2. Show Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                show_inventory(inventory, num_products);
                break;
            case 3:
                update_product(inventory, num_products);
                break;
            case 4:
                delete_product(inventory, &num_products);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Add new product to inventory
void add_product(struct Product inventory[], int* num_products) {
    // Check if inventory is full
    if (*num_products == MAX_ITEMS) {
        printf("\nInventory is full. Cannot add more products.\n");
        return;
    }

    // Prompt user for new product information
    struct Product new_product;
    printf("\nEnter name of product: ");
    scanf("%s", new_product.name);
    printf("Enter quantity of product: ");
    scanf("%d", &new_product.quantity);
    printf("Enter price of product: $");
    scanf("%f", &new_product.price);

    // Add new product to inventory
    inventory[*num_products] = new_product;
    (*num_products)++;

    printf("\nProduct added to inventory.\n");
}

// Show current inventory
void show_inventory(struct Product inventory[], int num_products) {
    printf("\n%-20s%-10s%s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s%-10d$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Update information of existing product
void update_product(struct Product inventory[], int num_products) {
    // Prompt user for product name to update
    char name[NAME_LENGTH];
    printf("\nEnter name of product to update: ");
    scanf("%s", name);

    // Find product in inventory
    int index = find_product(inventory, num_products, name);
    if (index == -1) {
        printf("\nProduct not found in inventory.\n");
        return;
    }

    // Prompt user for new product information
    struct Product updated_product;
    printf("\nEnter new quantity of product: ");
    scanf("%d", &updated_product.quantity);
    printf("Enter new price of product: $");
    scanf("%f", &updated_product.price);

    // Update product in inventory
    inventory[index].quantity = updated_product.quantity;
    inventory[index].price = updated_product.price;

    printf("\nProduct information updated.\n");
}

// Delete existing product from inventory
void delete_product(struct Product inventory[], int* num_products) {
    // Prompt user for product name to delete
    char name[NAME_LENGTH];
    printf("\nEnter name of product to delete: ");
    scanf("%s", name);

    // Find product in inventory
    int index = find_product(inventory, *num_products, name);
    if (index == -1) {
        printf("\nProduct not found in inventory.\n");
        return;
    }

    // Shift remaining products to fill deleted product's spot
    for (int i = index; i < *num_products - 1; i++) {
        inventory[i] = inventory[i+1];
    }
    (*num_products)--;

    printf("\nProduct deleted from inventory.\n");
}

// Find index of product in inventory
int find_product(struct Product inventory[], int num_products, char name[]) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}