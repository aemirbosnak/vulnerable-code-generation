//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size of the warehouse
#define MAX_NAME_LENGTH 25 // Maximum length of the product name

// Struct for the products in the warehouse
typedef struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

// Function to add a product to the warehouse
void addProduct(Product products[], int *numProducts) {
    if (*numProducts == MAX_SIZE) {
        printf("Warehouse is full!\n");
        return;
    }
    Product newProduct; // Create a new product
    printf("Enter the product name: ");
    fgets(newProduct.name, MAX_NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline character
    printf("Enter the quantity: ");
    scanf("%d", &newProduct.quantity);
    getchar(); // Remove newline character from previous input
    products[*numProducts] = newProduct; // Add new product to the end of the array
    (*numProducts)++; // Increment number of products in the warehouse
    printf("Product added successfully!\n");
}

// Function to remove a product from the warehouse
void removeProduct(Product products[], int *numProducts) {
    if (*numProducts == 0) {
        printf("Warehouse is empty!\n");
        return;
    }
    char productName[MAX_NAME_LENGTH];
    printf("Enter the product name: ");
    fgets(productName, MAX_NAME_LENGTH, stdin);
    productName[strcspn(productName, "\n")] = 0; // Remove newline character
    int indexToRemove = -1;
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(products[i].name, productName) == 0) { // If product name matches
            indexToRemove = i;
            break;
        }
    }
    if (indexToRemove == -1) {
        printf("Product not found!\n");
        return;
    }
    // Shift all products after the removed product to the left by one
    for (int i = indexToRemove; i < *numProducts - 1; i++) {
        products[i] = products[i+1];
    }
    (*numProducts)--; // Decrement number of products in the warehouse
    printf("Product removed successfully!\n");
}

// Function to display all products in the warehouse
void displayProducts(Product products[], int numProducts) {
    if (numProducts == 0) {
        printf("Warehouse is empty!\n");
        return;
    }
    printf("Products in the warehouse:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    Product products[MAX_SIZE]; // Array to store products in the warehouse
    int numProducts = 0; // Number of products currently in the warehouse
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Remove newline character from previous input
        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                removeProduct(products, &numProducts);
                break;
            case 3:
                displayProducts(products, numProducts);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}