//FormAI DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100

// Product structure
typedef struct {
    int id;
    char name[50];
    float price;
    int stock;
} Product;

// Global variables
int productCount = 0;
Product productList[MAX_PRODUCTS];

// Function declarations
void addProduct();
void removeProduct();
void displayProductList();
void displayMenu();

int main() {

    int choice = 0;

    // Welcome message
    printf("---------------------\n");
    printf("Product Inventory System\n");
    printf("---------------------\n\n");

    // Display menu
    while (choice != 4) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayProductList();
                break;
            case 4:
                printf("Thank you for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid input! Please enter a number between 1 and 4.\n");
                break;
        }
    }

    return 0;
}

// Function to add a product to the inventory
void addProduct() {
    Product product;

    // Prompt user for product information
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    printf("Enter product stock: ");
    scanf("%d", &product.stock);

    // Assign unique ID and add product to list
    product.id = productCount + 1;
    productList[productCount++] = product;

    printf("Product added successfully!\n\n");
}

// Function to remove a product from the inventory
void removeProduct() {
    int productId = 0;
    int i = 0;
    int productFound = 0;

    printf("Enter product ID to remove: ");
    scanf("%d", &productId);

    // Search for product with given ID
    for (i = 0; i < productCount; i++) {
        if (productId == productList[i].id) {
            // Shift products to the left to remove product
            memmove(&productList[i], &productList[i+1], sizeof(Product) * (productCount-i-1));
            productFound = 1;
            break;
        }
    }

    if (productFound) {
        productCount--;
        printf("Product removed successfully!\n\n");
    } else {
        printf("Product with ID %d not found!\n\n", productId);
    }
}

// Function to display the list of products
void displayProductList() {
    int i = 0;

    printf("Product ID\tProduct Name\tProduct Price\tProduct Stock\n");
    for (i = 0; i < productCount; i++) {
        printf("%d\t\t%s\t\t%.2f\t\t%d\n", productList[i].id, productList[i].name, productList[i].price, productList[i].stock);
    }

    printf("\n");
}

// Function to display the main menu
void displayMenu() {
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Display product list\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}