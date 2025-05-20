//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

void addProduct(Product* products, int numProducts) {
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

void printProduct(Product product) {
    printf("Name: %s\n", product.name);
    printf("Description: %s\n", product.description);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: $%.2lf\n\n", product.price);
}

void printInventory(Product* products, int numProducts) {
    printf("Inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        printProduct(products[i]);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("Enter 1 to add a product, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addProduct(products, numProducts);
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    printInventory(products, numProducts);

    return 0;
}