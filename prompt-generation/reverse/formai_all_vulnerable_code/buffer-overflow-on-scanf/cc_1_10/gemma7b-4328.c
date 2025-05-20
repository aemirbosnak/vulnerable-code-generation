//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];

void displayProducts() {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].quantity > 0) {
            printf("%s (%.2f) - %d units\n", products[i].name, products[i].price, products[i].quantity);
        }
    }
}

void addProduct() {
    char name[50];
    int quantity;
    float price;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].quantity == 0) {
            products[i] = newProduct;
            break;
        }
    }
}

void updateQuantity(char *name, int quantity) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity = quantity;
            break;
        }
    }
}

void removeProduct(char *name) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity = 0;
            break;
        }
    }
}

int main() {
    int choice;

    displayProducts();

    printf("Enter 1 to add product, 2 to update quantity, 3 to remove product: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            updateQuantity("Product Name", 10);
            break;
        case 3:
            removeProduct("Product Name");
            break;
        default:
            printf("Invalid choice\n");
    }

    displayProducts();

    return 0;
}