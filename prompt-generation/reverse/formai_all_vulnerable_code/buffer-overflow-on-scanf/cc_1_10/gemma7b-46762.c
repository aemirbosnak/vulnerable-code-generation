//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a product
typedef struct product {
    char name[20];
    int quantity;
    float price;
} product;

// Function to add a product to the inventory
void addProduct(product *products, int *numProducts) {
    // Allocate memory for a new product
    products = (product *)realloc(products, (*numProducts + 1) * sizeof(product));

    // Get the product name, quantity, and price
    printf("Enter the product name: ");
    scanf("%s", products[*numProducts].name);

    printf("Enter the product quantity: ");
    scanf("%d", &products[*numProducts].quantity);

    printf("Enter the product price: ");
    scanf("%f", &products[*numProducts].price);

    // Increment the number of products
    (*numProducts)++;
}

// Function to display the inventory
void displayInventory(product *products, int numProducts) {
    // Print the inventory
    printf("Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %d - %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    // Create an array of products
    product *products = NULL;

    // Initialize the number of products to 0
    int numProducts = 0;

    // Add some products to the inventory
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);

    // Display the inventory
    displayInventory(products, numProducts);

    return 0;
}