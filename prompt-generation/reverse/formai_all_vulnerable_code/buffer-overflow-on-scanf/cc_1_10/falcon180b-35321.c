//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 1000
#define MAX_QUANTITY 100
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
    int quantity;
    char category[MAX_CATEGORY_LENGTH];
} Product;

void createProduct(Product* product) {
    printf("Enter product name: ");
    scanf("%s", product->name);

    printf("Enter product description: ");
    scanf("%s", product->description);

    printf("Enter product price: ");
    scanf("%f", &product->price);

    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);

    printf("Enter product category: ");
    scanf("%s", product->category);
}

void displayProduct(Product product) {
    printf("Product Name: %s\n", product.name);
    printf("Product Description: %s\n", product.description);
    printf("Product Price: $%.2f\n", product.price);
    printf("Product Quantity: %d\n", product.quantity);
    printf("Product Category: %s\n", product.category);
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while(numProducts < MAX_PRODUCTS) {
        printf("Enter product information (leave any field blank to stop):\n");
        createProduct(&products[numProducts]);
        numProducts++;
    }

    printf("\nProduct Inventory:\n");
    for(int i=0; i<numProducts; i++) {
        displayProduct(products[i]);
    }

    return 0;
}