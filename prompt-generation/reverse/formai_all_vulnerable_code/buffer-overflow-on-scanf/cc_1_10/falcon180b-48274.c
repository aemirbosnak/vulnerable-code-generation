//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE_LENGTH 10
#define MAX_QUANTITY_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char price[MAX_PRICE_LENGTH];
    int quantity;
} Product;

void addProduct(Product* products, int numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter product description: ");
    scanf("%s", products[numProducts].description);
    printf("Enter product price: ");
    scanf("%s", products[numProducts].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);
}

void printProduct(Product product) {
    printf("Product Name: %s\n", product.name);
    printf("Product Description: %s\n", product.description);
    printf("Product Price: $%s\n", product.price);
    printf("Product Quantity: %d\n", product.quantity);
}

void printAllProducts(Product* products, int numProducts) {
    printf("Product Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printProduct(products[i]);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("Enter 'A' to add a product or any other key to exit: ");
        char input;
        scanf("%c", &input);

        if (input == 'A' || input == 'a') {
            addProduct(products, numProducts);
            numProducts++;
        } else {
            printf("Exiting...\n");
            break;
        }
    }

    printAllProducts(products, numProducts);

    return 0;
}