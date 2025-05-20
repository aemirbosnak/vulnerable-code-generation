//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: synchronous
// C Program for Product Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Product structure
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function to add a product
void addProduct(Product *products, int *numProducts) {
    // Get product details
    printf("Enter product ID: ");
    int id = 0;
    scanf("%d", &id);
    printf("Enter product name: ");
    char name[50];
    scanf("%s", name);
    printf("Enter product quantity: ");
    int quantity = 0;
    scanf("%d", &quantity);
    printf("Enter product price: ");
    float price = 0.0;
    scanf("%f", &price);

    // Add product to array
    products[*numProducts].id = id;
    strcpy(products[*numProducts].name, name);
    products[*numProducts].quantity = quantity;
    products[*numProducts].price = price;

    // Increment number of products
    (*numProducts)++;
}

// Function to display all products
void displayAllProducts(Product *products, int numProducts) {
    // Print header
    printf("ID\tName\tQuantity\tPrice\n");

    // Print all products
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to update a product
void updateProduct(Product *products, int numProducts) {
    // Get product ID
    printf("Enter product ID: ");
    int id = 0;
    scanf("%d", &id);

    // Find product with given ID
    int index = -1;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if product was found
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    // Update product quantity and price
    printf("Enter new quantity: ");
    int quantity = 0;
    scanf("%d", &quantity);
    products[index].quantity = quantity;
    printf("Enter new price: ");
    float price = 0.0;
    scanf("%f", &price);
    products[index].price = price;
}

// Function to delete a product
void deleteProduct(Product *products, int *numProducts) {
    // Get product ID
    printf("Enter product ID: ");
    int id = 0;
    scanf("%d", &id);

    // Find product with given ID
    int index = -1;
    for (int i = 0; i < *numProducts; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if product was found
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    // Delete product
    for (int i = index; i < *numProducts - 1; i++) {
        products[i] = products[i + 1];
    }

    // Decrement number of products
    (*numProducts)--;
}

int main() {
    // Initialize product array and number of products
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    // Menu
    int choice = 0;
    while (choice != 4) {
        printf("1. Add product\n");
        printf("2. Display all products\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Add product
        if (choice == 1) {
            addProduct(products, &numProducts);
        }

        // Display all products
        if (choice == 2) {
            displayAllProducts(products, numProducts);
        }

        // Update product
        if (choice == 3) {
            updateProduct(products, numProducts);
        }

        // Delete product
        if (choice == 4) {
            deleteProduct(products, &numProducts);
        }
    }

    return 0;
}