//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: calm
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

void insertProduct() {
    products[MAX_PRODUCTS - 1].quantity = 0;
    products[MAX_PRODUCTS - 1].price = 0.0f;
    printf("Enter product name: ");
    scanf("%s", products[MAX_PRODUCTS - 1].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[MAX_PRODUCTS - 1].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[MAX_PRODUCTS - 1].price);
    products[MAX_PRODUCTS - 1].quantity++;
}

void updateProductQuantity(char *name, int quantity) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity = quantity;
        }
    }
}

void updateProductPrice(char *name, float price) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].price = price;
        }
    }
}

void listProducts() {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].quantity > 0) {
            printf("%s, %d, %.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    insertProduct();
    insertProduct();
    updateProductQuantity("Product 1", 10);
    updateProductPrice("Product 2", 50.0f);
    listProducts();

    return 0;
}