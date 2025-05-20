//FormAI DATASET v1.0 Category: Product Inventory System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products

// Product structure
typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function prototypes
void display_menu();
void add_product(Product products[], int* count);
void remove_product(Product products[], int* count);
void update_product(Product products[], int count);
void display_products(Product products[], int count);

// Main function
int main() {
    Product products[MAX_PRODUCTS]; // Array of products
    int count = 0; // Number of products in the inventory
    int choice; // User's menu choice

    // Main loop of program
    while (1) {
        display_menu(); // Display the menu options
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product(products, &count);
                break;
            case 2:
                remove_product(products, &count);
                break;
            case 3:
                update_product(products, count);
                break;
            case 4:
                display_products(products, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to display the main menu
void display_menu() {
    printf("\n=== PRODUCT INVENTORY SYSTEM ===\n");
    printf("1. Add a new product\n");
    printf("2. Remove a product\n");
    printf("3. Update a product\n");
    printf("4. Display all products\n");
    printf("5. Exit\n");
}

// Function to add a new product
void add_product(Product products[], int* count) {
    Product new_product; // New product to be added
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    // Assign ID for the new product
    new_product.id = *count + 1;

    // Add the new product to the inventory
    products[*count] = new_product;
    (*count)++;
    printf("Product added successfully.\n");
}

// Function to remove a product
void remove_product(Product products[], int* count) {
    int remove_id; // ID of product to be removed
    printf("Enter product ID to remove: ");
    scanf("%d", &remove_id);

    for (int i = 0; i < *count; i++) {
        if (products[i].id == remove_id) {
            // Shift the remaining products to fill the removed product's index
            for (int j = i; j < *count - 1; j++) {
                products[j] = products[j+1];
            }
            (*count)--;
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to update a product
void update_product(Product products[], int count) {
    int update_id; // ID of product to be updated
    printf("Enter product ID to update: ");
    scanf("%d", &update_id);

    for (int i = 0; i < count; i++) {
        if (products[i].id == update_id) {
            printf("Enter new product name: ");
            scanf("%s", products[i].name);
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
            printf("Product updated successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to display all products in the inventory
void display_products(Product products[], int count) {
    printf("\n ID |     NAME     | QUANTITY |  PRICE  \n");
    printf("----|--------------|----------|---------\n");
    for (int i = 0; i < count; i++) {
        printf(" %02d | %-12s | %8d | $%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
    printf("----|--------------|----------|---------\n");
}