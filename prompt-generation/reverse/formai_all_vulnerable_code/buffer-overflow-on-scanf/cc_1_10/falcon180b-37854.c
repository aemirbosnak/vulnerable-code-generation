//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char price[MAX_PRICE_LENGTH];
} Product;

void addProduct(Product products[], int numProducts) {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char price[MAX_PRICE_LENGTH];

    printf("Enter product name: ");
    scanf("%s", name);
    strcpy(products[numProducts].name, name);

    printf("Enter product description: ");
    scanf("%s", description);
    strcpy(products[numProducts].description, description);

    printf("Enter product price: ");
    scanf("%s", price);
    strcpy(products[numProducts].price, price);

    numProducts++;
}

void displayProducts(Product products[], int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Price: $%.2f\n\n", atof(products[i].price));
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;

    printf("Welcome to the product inventory system!\n\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        int option;
        scanf("%d", &option);

        switch (option) {
        case 1:
            addProduct(products, numProducts);
            break;
        case 2:
            displayProducts(products, numProducts);
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option!\n");
        }
    }

    return 0;
}