//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product new_product;
    printf("Enter product name: ");
    scanf(" %[^\n]", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    inventory[product_count++] = new_product;
    printf("Product added successfully!\n");
}

void view_products() {
    if (product_count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nInventory:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("-------------------------------------\n");
    for (int i = 0; i < product_count; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void delete_product() {
    if (product_count == 0) {
        printf("No products to delete.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the product name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < product_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < product_count - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift products left
            }
            product_count--;
            printf("Product '%s' deleted successfully!\n", name);
            return;
        }
    }
    printf("Product '%s' not found in inventory.\n", name);
}

void display_menu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Delete Product\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

int main() {
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}