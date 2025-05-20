//FormAI DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for product
struct product {
    int id;
    char name[30];
    int quantity;
    float price;
};

// Function declarations
void addProduct();
void deleteProduct();
void searchProduct();
void displayAllProducts();

// Global variables
struct product products[100];
int totalProducts = 0;

int main() {
    int option;

    printf("Welcome to the Product Inventory System!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Add a product\n");
        printf("2. Delete a product\n");
        printf("3. Search for a product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                addProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                displayAllProducts();
                break;
            case 5:
                printf("Thank you for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

void addProduct() {
    struct product newProduct;

    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[totalProducts++] = newProduct;

    printf("Product added successfully.\n\n");
}

void deleteProduct() {
    int productId, i, j;

    printf("Enter product ID: ");
    scanf("%d", &productId);

    for (i = 0; i < totalProducts; i++) {
        if (products[i].id == productId) {
            for (j = i; j < totalProducts - 1; j++) {
                products[j] = products[j+1];
            }
            totalProducts--;
            printf("Product deleted successfully.\n\n");
            return;
        }
    }

    printf("Product not found.\n\n");
}

void searchProduct() {
    int productId, i;

    printf("Enter product ID: ");
    scanf("%d", &productId);

    for (i = 0; i < totalProducts; i++) {
        if (products[i].id == productId) {
            printf("Product details:\n");
            printf("ID: %d\n", products[i].id);
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n\n", products[i].price);
            return;
        }
    }

    printf("Product not found.\n\n");
}

void displayAllProducts() {
    int i;

    printf("Product inventory:\n\n");
    printf("ID\tName\t\tQuantity\tPrice\n");

    for (i = 0; i < totalProducts; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n",
            products[i].id,
            products[i].name,
            products[i].quantity,
            products[i].price);
    }

    printf("\n");
}