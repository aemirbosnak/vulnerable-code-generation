//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
// Futuristic C Product Inventory System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store product information
struct Product {
    char name[100];
    int quantity;
    float price;
};

// Function to display product information
void displayProduct(struct Product product) {
    printf("Name: %s\nQuantity: %d\nPrice: %f\n\n", product.name, product.quantity, product.price);
}

// Function to add a new product
void addProduct(struct Product *products, int *numProducts) {
    // Get input from user
    printf("Enter product name: ");
    scanf("%s", &products[*numProducts].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*numProducts].price);

    // Increment number of products
    (*numProducts)++;
}

// Function to remove a product
void removeProduct(struct Product *products, int *numProducts) {
    // Get input from user
    printf("Enter product name: ");
    scanf("%s", &products[*numProducts].name);

    // Find the product index
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].name, products[*numProducts].name) == 0) {
            break;
        }
    }

    // Remove the product from the array
    if (i < *numProducts) {
        memmove(&products[i], &products[i + 1], (*numProducts - i) * sizeof(struct Product));
        (*numProducts)--;
    } else {
        printf("Product not found\n");
    }
}

// Function to display all products
void displayAllProducts(struct Product *products, int numProducts) {
    int i;
    for (i = 0; i < numProducts; i++) {
        displayProduct(products[i]);
    }
}

int main() {
    // Initialize variables
    struct Product products[100];
    int numProducts = 0;

    // Main menu
    char choice;
    do {
        printf("Menu\n");
        printf("A) Add product\n");
        printf("R) Remove product\n");
        printf("D) Display all products\n");
        printf("Q) Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Execute the user's choice
        switch (choice) {
            case 'A':
                addProduct(products, &numProducts);
                break;
            case 'R':
                removeProduct(products, &numProducts);
                break;
            case 'D':
                displayAllProducts(products, numProducts);
                break;
            case 'Q':
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 'Q');

    return 0;
}