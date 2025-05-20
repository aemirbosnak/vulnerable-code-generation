//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int numProducts, char name[], int quantity, float price) {
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity += quantity;
            return;
        }
    }
    strcpy(products[numProducts].name, name);
    products[numProducts].quantity = quantity;
    products[numProducts].price = price;
    numProducts++;
}

void displayProducts(Product products[], int numProducts) {
    int i;
    for (i = 0; i < numProducts; i++) {
        printf("%s - %d units - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;
    char name[50];
    int quantity;
    float price;

    addProduct(products, numProducts, "Apples", 10, 1.99);
    addProduct(products, numProducts, "Oranges", 5, 2.49);
    addProduct(products, numProducts, "Bananas", 15, 1.29);

    displayProducts(products, numProducts);

    printf("\nEnter product name: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: $");
    scanf("%f", &price);

    addProduct(products, numProducts, name, quantity, price);

    displayProducts(products, numProducts);
}