//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 10000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    float price;
} Product;

void addProduct(Product* products, int numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter product description: ");
    scanf("%s", products[numProducts].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[numProducts].price);
    numProducts++;
}

void displayProducts(Product* products, int numProducts) {
    printf("Product ID\tName\tDescription\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%s\t%d\t$%.2f\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    addProduct(products, numProducts);

    while (1) {
        displayProducts(products, numProducts);

        printf("\nDo you want to add another product? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
        addProduct(products, numProducts);
    }

    return 0;
}