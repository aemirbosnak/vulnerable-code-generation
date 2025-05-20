//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store product information
typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

// Define a function to add a product to the inventory
void addProduct(Product *product) {
    printf("Enter product name: ");
    scanf("%s", product->name);

    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);

    printf("Enter product price: ");
    scanf("%f", &product->price);
}

// Define a function to display all products in the inventory
void displayProducts(Product *products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %d - %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Define a function to update the quantity of a product
void updateQuantity(Product *product) {
    printf("Enter the new quantity: ");
    scanf("%d", &product->quantity);
}

// Define a function to delete a product from the inventory
void deleteProduct(Product *products, int *numProducts) {
    printf("Enter the name of the product to delete: ");
    char name[50];
    scanf("%s", name);

    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i] = products[*numProducts - 1];
            *numProducts--;
            break;
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

    // Display all products in the inventory
    displayProducts(products, numProducts);

    // Update the quantity of a product
    updateQuantity(&products[0]);

    // Delete a product from the inventory
    deleteProduct(products, &numProducts);

    // Display all products in the inventory after updates
    displayProducts(products, numProducts);

    return 0;
}