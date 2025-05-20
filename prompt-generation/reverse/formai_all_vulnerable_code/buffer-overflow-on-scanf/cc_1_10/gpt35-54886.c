//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of products that the warehouse can hold
#define MAX_PRODUCTS 100

// Define the maximum number of characters allowed for the product name and supplier name
#define MAX_CHARS 50

// Define a struct for each product that includes the name, supplier, quantity, and price
struct Product {
    char name[MAX_CHARS];
    char supplier[MAX_CHARS];
    int quantity;
    float price;
};

// Initialize the array of products
struct Product products[MAX_PRODUCTS];

// Initialize the number of products in the warehouse to zero
int numProducts = 0;

// Function to add a product to the warehouse
void addProduct() {
    // Check if the maximum number of products has been reached
    if (numProducts >= MAX_PRODUCTS) {
        printf("Unable to add product, warehouse is full.\n");
        return;
    }

    // Initialize the new product struct
    struct Product newProduct;

    // Prompt the user for the product name and supplier name
    printf("Enter the product name: ");
    fgets(newProduct.name, MAX_CHARS, stdin);
    newProduct.name[strlen(newProduct.name) - 1] = '\0'; // Remove the newline character

    printf("Enter the supplier name: ");
    fgets(newProduct.supplier, MAX_CHARS, stdin);
    newProduct.supplier[strlen(newProduct.supplier) - 1] = '\0'; // Remove the newline character

    // Prompt the user for the quantity and price
    printf("Enter the quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter the price: ");
    scanf("%f", &newProduct.price);

    // Add the new product struct to the array of products and increment the number of products in the warehouse
    products[numProducts] = newProduct;
    numProducts++;

    // Print a success message
    printf("Product added to warehouse.\n");
}

// Function to remove a product from the warehouse
void removeProduct() {
    // Check if there are any products in the warehouse
    if (numProducts == 0) {
        printf("Unable to remove product, warehouse is empty.\n");
        return;
    }

    // Prompt the user for the name of the product to remove
    char productName[MAX_CHARS];
    printf("Enter the name of the product to remove: ");
    fgets(productName, MAX_CHARS, stdin);
    productName[strlen(productName) - 1] = '\0'; // Remove the newline character

    // Search for the product in the array of products
    int index = -1;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            index = i;
            break;
        }
    }

    // If the product was not found, print an error message and return
    if (index == -1) {
        printf("Product not found in warehouse.\n");
        return;
    }

    // Shift all the products after the removed product back one index
    for (int i = index; i < numProducts - 1; i++) {
        products[i] = products[i + 1];
    }

    // Decrement the number of products in the warehouse
    numProducts--;

    // Print a success message
    printf("Product removed from warehouse.\n");
}

// Function to print the list of products in the warehouse
void listProducts() {
    // Check if there are any products in the warehouse
    if (numProducts == 0) {
        printf("Warehouse is empty.\n");
        return;
    }

    // Print a header for the list of products
    printf("Product Name | Supplier Name | Quantity | Price\n");

    // Loop through the array of products and print each product's information
    for (int i = 0; i < numProducts; i++) {
        printf("%-12s | %-13s | %-8d | %-6.2f\n", products[i].name, products[i].supplier, products[i].quantity, products[i].price);
    }
}

// Main function
int main() {
    // Initialize the choice variable to zero
    int choice = 0;

    // Loop until the user chooses to exit
    while (choice != 4) {
        // Print the menu options
        printf("Warehouse Management System\n");
        printf("---------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List products\n");
        printf("4. Exit\n");

        // Prompt the user for their choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Flush the input buffer to prevent issues with fgets
        fflush(stdin);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                listProducts();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

        // Print a separator line between each iteration of the loop
        printf("-------------------------------------------------\n");
    }

    // Exit the program
    return 0;
}