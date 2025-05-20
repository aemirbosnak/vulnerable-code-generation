//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000.00

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int numProducts) {
    if (numProducts >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

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

void displayProducts(Product products[], int numProducts) {
    printf("Product Name\tProduct Description\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t%s\t%d\t%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addProduct(products, numProducts);
            break;
        case 2:
            displayProducts(products, numProducts);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}