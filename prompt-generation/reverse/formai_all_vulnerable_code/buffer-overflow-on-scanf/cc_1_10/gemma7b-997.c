//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a structure to store product information
typedef struct Product {
    char name[50];
    int quantity;
    float price;
    char category[50];
} Product;

// Define a function to add a product to the inventory
void addProduct(Product *product) {
    printf("Enter product name: ");
    scanf("%s", product->name);

    printf("Enter quantity: ");
    scanf("%d", &product->quantity);

    printf("Enter price: ");
    scanf("%f", &product->price);

    printf("Enter category: ");
    scanf("%s", product->category);
}

// Define a function to display all products
void displayProducts(Product *products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %d - %.2f - %s\n", products[i].name, products[i].quantity, products[i].price, products[i].category);
    }
}

// Define a function to find a product by name
Product *findProductByName(Product *products, int numProducts, char *name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return &products[i];
        }
    }

    return NULL;
}

// Define a function to update the quantity of a product
void updateQuantity(Product *product, int newQuantity) {
    product->quantity = newQuantity;
}

// Define a function to calculate the total cost of a product
float calculateTotalCost(Product *product) {
    return product->price * product->quantity;
}

int main() {
    // Create an array of products
    Product products[10];

    // Initialize the number of products to 0
    int numProducts = 0;

    // Add some products to the inventory
    addProduct(&products[numProducts++]);
    addProduct(&products[numProducts++]);
    addProduct(&products[numProducts++]);

    // Display all products
    displayProducts(products, numProducts);

    // Find a product by name
    Product *product = findProductByName(products, numProducts, "Product 2");

    // Update the quantity of the product
    updateQuantity(product, 10);

    // Display the updated product information
    displayProducts(products, numProducts);

    // Calculate the total cost of the product
    float totalCost = calculateTotalCost(product);

    // Print the total cost
    printf("Total cost: %.2f\n", totalCost);

    return 0;
}