//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

void addProduct(Product products[], int numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);

    printf("Enter product description: ");
    scanf("%s", products[numProducts].description);

    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[numProducts].price);

    numProducts++;
}

void displayProduct(Product product) {
    printf("Product name: %s\n", product.name);
    printf("Product description: %s\n", product.description);
    printf("Product quantity: %d\n", product.quantity);
    printf("Product price: $%.2lf\n\n", product.price);
}

void searchProduct(Product products[], int numProducts, char searchTerm[]) {
    int i;
    for(i = 0; i < numProducts; i++) {
        if(strstr(products[i].name, searchTerm)!= NULL || strstr(products[i].description, searchTerm)!= NULL) {
            displayProduct(products[i]);
        }
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while(numProducts < MAX_PRODUCTS) {
        addProduct(products, numProducts);
    }

    printf("Product inventory:\n");
    for(int i = 0; i < numProducts; i++) {
        displayProduct(products[i]);
    }

    char searchTerm[MAX_NAME_LENGTH];
    printf("Enter search term: ");
    scanf("%s", searchTerm);

    searchProduct(products, numProducts, searchTerm);

    return 0;
}