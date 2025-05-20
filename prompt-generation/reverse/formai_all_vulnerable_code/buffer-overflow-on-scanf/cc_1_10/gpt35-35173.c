//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

/* Product structure */
struct Product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
};

/* Global variables */
int numProducts = 0;
struct Product products[MAX_PRODUCTS];

/* Function prototypes */
void addProduct();
void displayProducts();
void updateProduct();
void removeProduct();

/* Main function */
int main() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("========================\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Update a product\n");
        printf("4. Remove a product\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}

/* Function to add a new product */
void addProduct() {
    if (numProducts == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }
    struct Product product;
    printf("\nEnter product details:\n");
    printf("Name: ");
    fflush(stdin);
    gets(product.name);
    printf("Description: ");
    fflush(stdin);
    gets(product.description);
    printf("Quantity: ");
    scanf("%d", &product.quantity);
    printf("Price: ");
    scanf("%f", &product.price);
    products[numProducts++] = product;
    printf("\nProduct added successfully!\n");
}

/* Function to display all products */
void displayProducts() {
    if (numProducts == 0) {
        printf("Error: No products found.\n");
        return;
    }
    printf("\n%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("================================================\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%-10d %-25s %-10d %-10.2f\n", i + 1, products[i].name, products[i].quantity, products[i].price);
    }
}

/* Function to update a product */
void updateProduct() {
    int id;
    if (numProducts == 0) {
        printf("Error: No products found.\n");
        return;
    }
    displayProducts();
    printf("\nEnter product ID to update: ");
    scanf("%d", &id);
    if (id < 1 || id > numProducts) {
        printf("Error: Invalid ID.\n");
        return;
    }
    struct Product product;
    printf("\nEnter new product details:\n");
    printf("Name: ");
    fflush(stdin);
    gets(product.name);
    printf("Description: ");
    fflush(stdin);
    gets(product.description);
    printf("Quantity: ");
    scanf("%d", &product.quantity);
    printf("Price: ");
    scanf("%f", &product.price);
    products[id - 1] = product;
    printf("\nProduct updated successfully!\n");
}

/* Function to remove a product */
void removeProduct() {
    int id;
    if (numProducts == 0) {
        printf("Error: No products found.\n");
        return;
    }
    displayProducts();
    printf("\nEnter product ID to remove: ");
    scanf("%d", &id);
    if (id < 1 || id > numProducts) {
        printf("Error: Invalid ID.\n");
        return;
    }
    for (int i = id - 1; i < numProducts - 1; i++) {
        products[i] = products[i + 1];
    }
    numProducts--;
    printf("\nProduct removed successfully!\n");
}