//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store product information
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Function to add a product to the inventory
void addProduct(Product *product) {
    printf("Enter the product name: ");
    scanf("%s", product->name);

    printf("Enter the product quantity: ");
    scanf("%d", &product->quantity);

    printf("Enter the product price: ");
    scanf("%f", &product->price);
}

// Function to list all products in the inventory
void listProducts(Product *products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("%s: %d, $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to search for a product in the inventory
void searchProduct(Product *products, int numProducts) {
    char searchName[50];

    printf("Enter the product name: ");
    scanf("%s", searchName);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("%s: %d, $%.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    // Create an array of products
    Product products[100];

    // Initialize the number of products to 0
    int numProducts = 0;

    // Add a product to the inventory
    addProduct(&products[numProducts]);
    numProducts++;

    // Add another product to the inventory
    addProduct(&products[numProducts]);
    numProducts++;

    // List all products in the inventory
    listProducts(products, numProducts);

    // Search for a product in the inventory
    searchProduct(products, numProducts);

    return 0;
}