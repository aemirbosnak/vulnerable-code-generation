//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_LENGTH 20

typedef struct Product {
    int id;
    char name[MAX_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

// Function to add a new product to the warehouse
void addProduct() {
    Product product;

    // Get the product details from the user
    printf("Enter product name: ");
    fgets(product.name, MAX_LENGTH, stdin);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);

    // Generate a unique ID for the product
    product.id = numProducts + 1;

    // Add the product to the warehouse
    products[numProducts] = product;
    numProducts++;

    printf("Product added successfully.\n");
}

// Function to display a list of all products in the warehouse
void viewProducts() {
    printf("Product ID\tName\t\tQuantity\n");

    for (int i = 0; i < numProducts; i++) {
        Product product = products[i];
        printf("%d\t\t%s\t\t%d\n", product.id, product.name, product.quantity);
    }
}

// Function to remove a product from the warehouse
void removeProduct() {
    int id;

    // Get the ID of the product to remove from the user
    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    // Find the product in the warehouse
    int index = -1;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    // Remove the product from the warehouse
    for (int i = index; i < numProducts - 1; i++) {
        products[i] = products[i+1];
    }
    numProducts--;

    printf("Product removed successfully.\n");
}

int main() {
    int option;

    do {
        // Print the menu options
        printf("\nWarehouse management system\n");
        printf("============================\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Remove product\n");
        printf("4. Quit\n\n");

        // Get the user's choice
        printf("Enter option: ");
        scanf("%d", &option);
        getchar();

        // Perform the selected action
        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 4);

    return 0;
}