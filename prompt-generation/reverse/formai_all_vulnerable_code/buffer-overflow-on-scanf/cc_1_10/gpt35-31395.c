//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

// Define a structure for each product
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

// Function to add a new product to the inventory
void add_product() {
    Product new_product;

    // Get the name of the new product
    printf("Enter the name of the product: ");
    scanf("%s", new_product.name);

    // Get the quantity of the new product
    printf("Enter the quantity of the product: ");
    scanf("%d", &new_product.quantity);

    // Get the price of the new product
    printf("Enter the price of the product: ");
    scanf("%f", &new_product.price);

    // Add the new product to the inventory
    inventory[num_products] = new_product;
    num_products++;

    printf("Product added successfully!\n");
}

// Function to remove a product from the inventory
void remove_product() {
    int product_index;

    // Get the index of the product to remove
    printf("Enter the index of the product to remove: ");
    scanf("%d", &product_index);

    // Shift all the elements after the product to the left
    for (int i = product_index; i < num_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    // Decrement the number of products
    num_products--;

    printf("Product removed successfully!\n");
}

// Function to display all the products in the inventory
void display_inventory() {
    printf("Inventory:\n");
    printf("-------------------------------------------------\n");
    printf("Index\t| Name\t| Quantity\t| Price\t\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t|%s\t|%d\t\t|$%.2f\n", i, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to search the inventory for a particular product
void search_product() {
    char product_name[50];

    // Get the name of the product to search for
    printf("Enter the name of the product to search for: ");
    scanf("%s", product_name);

    // Search for the product and display its details
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, product_name) == 0) {
            printf("Product found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: $%.2f\n", inventory[i].price);
            return;
        }
    }

    printf("Product not found.\n");
}

int main() {
    int choice;

    // Display the menu and get the user's choice
    while (1) {
        printf("\n\n");
        printf("Inventory Management System\n");
        printf("------------------------------\n");
        printf("1. Add new product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Search for product\n");
        printf("5. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                add_product();
                break;

            case 2:
                remove_product();
                break;

            case 3:
                display_inventory();
                break;

            case 4:
                search_product();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}