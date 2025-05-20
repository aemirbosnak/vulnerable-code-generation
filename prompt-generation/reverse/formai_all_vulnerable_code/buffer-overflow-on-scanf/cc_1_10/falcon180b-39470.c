//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter quantity: ");
    scanf("%d", &products[numProducts].quantity);
    printf("Enter price: ");
    scanf("%f", &products[numProducts].price);
    numProducts++;
}

void displayProducts(Product products[], int numProducts) {
    printf("Product Name\tQuantity\tPrice\n");
    for(int i=0; i<numProducts; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while(numProducts < MAX_PRODUCTS) {
        addProduct(products, numProducts);
        printf("Do you want to add another product? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if(choice!= 'y') {
            break;
        }
    }

    displayProducts(products, numProducts);

    return 0;
}