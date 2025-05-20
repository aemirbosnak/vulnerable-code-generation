//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void createProduct(Product *product) {
    printf("Enter product id: ");
    scanf("%d", &product->id);

    printf("Enter product name: ");
    scanf("%s", product->name);

    printf("Enter product quantity: ");
    scanf("%d", &product->quantity);

    printf("Enter product price: ");
    scanf("%f", &product->price);
}

void displayProduct(Product product) {
    printf("Product ID: %d\n", product.id);
    printf("Product Name: %s\n", product.name);
    printf("Product Quantity: %d\n", product.quantity);
    printf("Product Price: $%.2f\n", product.price);
}

void updateQuantity(Product *product, int newQuantity) {
    product->quantity = newQuantity;
}

void updatePrice(Product *product, float newPrice) {
    product->price = newPrice;
}

int main() {
    Product product1;
    createProduct(&product1);
    displayProduct(product1);

    updateQuantity(&product1, 10);
    updatePrice(&product1, 19.99);
    displayProduct(product1);

    return 0;
}