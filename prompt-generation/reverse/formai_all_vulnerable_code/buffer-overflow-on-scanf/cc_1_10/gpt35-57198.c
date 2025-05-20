//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50

// Define a product struct to hold information about a single product
struct product {
    char name[20];
    float price;
    int quantity;
};

// Define a struct to hold the list of products and the count of products
struct product_inventory {
    struct product inventory[MAX_PRODUCTS];
    int count;
};

// Function to add a product to the inventory
void add_product(struct product_inventory *inventory) {
    struct product new_product;
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    inventory->inventory[inventory->count] = new_product;
    inventory->count++;
}

// Function to list all products in the inventory
void list_products(struct product_inventory *inventory) {
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
    for (int i = 0; i < inventory->count; i++) {
        printf("%-20s %-10.2f %-10d\n", inventory->inventory[i].name, inventory->inventory[i].price, inventory->inventory[i].quantity);
    }
}

// Function to remove a product from the inventory
void remove_product(struct product_inventory *inventory) {
    char product_name[20];
    printf("Enter product name: ");
    scanf("%s", product_name);
    for (int i = 0; i < inventory->count; i++) {
        if (strcmp(inventory->inventory[i].name, product_name) == 0) {
            for (int j = i; j < inventory->count - 1; j++) {
                inventory->inventory[j] = inventory->inventory[j + 1];
            }
            inventory->count--;
            printf("Product removed from inventory.\n");
            return;
        }
    }
    printf("Product not found in inventory.\n");
}

int main() {
    struct product_inventory inventory;
    inventory.count = 0;
    int choice;
    while (1) {
        printf("Welcome to Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. List all products\n");
        printf("3. Remove product\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product(&inventory);
                break;
            case 2:
                list_products(&inventory);
                break;
            case 3:
                remove_product(&inventory);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}