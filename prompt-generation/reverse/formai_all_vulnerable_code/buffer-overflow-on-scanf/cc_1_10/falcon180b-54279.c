//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
};

void addProduct(struct product *products, int numProducts) {
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

void displayProducts(struct product *products, int numProducts) {
    printf("Product ID\tProduct Name\tProduct Description\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%s\t%d\t$%.2f\n", i + 1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
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

    printf("\nProduct Inventory:\n");
    displayProducts(products, numProducts);

    return 0;
}