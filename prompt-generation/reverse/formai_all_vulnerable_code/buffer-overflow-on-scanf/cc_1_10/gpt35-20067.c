//FormAI DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct to hold product information
struct Product {
    char name[50];
    int id;
    float price;
    int quantity;
};

// Declare global variables
int numProducts = 0;
struct Product productList[100];

// Declare function prototypes
void addProduct();
void viewProducts();
void updateProduct();
void deleteProduct();

int main() {
    int choice;

    // Loop through program until user chooses to exit
    do {
        printf("\n----Product Inventory System----\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Update product\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}

// Function to add a product to the inventory
void addProduct() {
    struct Product newProduct;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    productList[numProducts++] = newProduct; // Add new product to product list
}

// Function to view all products in the inventory
void viewProducts() {
    if(numProducts == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("%-20s%-10s%-10s%-10s\n", "Product Name", "Product ID", "Price", "Quantity");
    for(int i = 0; i < numProducts; i++) {
        printf("%-20s%-10d%-10.2f%-10d\n", productList[i].name, productList[i].id, productList[i].price, productList[i].quantity);
    }
}

// Function to update a product in the inventory
void updateProduct() {
    int id;
    int productIndex = -1;

    printf("Enter product ID: ");
    scanf("%d", &id);

    // Find product index in the product list
    for(int i = 0; i < numProducts; i++) {
        if(productList[i].id == id) {
            productIndex = i;
            break;
        }
    }

    // Exit function if product not found in list
    if(productIndex == -1) {
        printf("Product not found.\n");
        return;
    }

    printf("Enter updated product name: ");
    scanf("%s", productList[productIndex].name);

    printf("Enter updated product ID: ");
    scanf("%d", &productList[productIndex].id);

    printf("Enter updated product price: ");
    scanf("%f", &productList[productIndex].price);

    printf("Enter updated product quantity: ");
    scanf("%d", &productList[productIndex].quantity);
}

// Function to delete a product from the inventory
void deleteProduct() {
    int id;
    int productIndex = -1;

    printf("Enter product ID: ");
    scanf("%d", &id);

    // Find product index in the product list
    for(int i = 0; i < numProducts; i++) {
        if(productList[i].id == id) {
            productIndex = i;
            break;
        }
    }

    // Exit function if product not found in list
    if(productIndex == -1) {
        printf("Product not found.\n");
        return;
    }

    // Shift all products in list to remove deleted product
    for(int i = productIndex; i < numProducts - 1; i++) {
        productList[i] = productList[i + 1];
    }

    numProducts--; // Decrement number of products in list
}