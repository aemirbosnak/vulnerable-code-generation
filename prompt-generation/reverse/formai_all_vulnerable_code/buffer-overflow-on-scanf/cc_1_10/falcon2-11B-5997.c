//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50

struct Product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
};

typedef struct Product Product;

int main() {
    Product products[MAX_PRODUCTS];

    int numProducts = 0;

    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    if (numProducts > MAX_PRODUCTS) {
        printf("Error: Too many products!\n");
        return 1;
    }

    printf("Enter the name of each product: ");
    for (int i = 0; i < numProducts; i++) {
        fgets(products[i].name, MAX_NAME_LENGTH, stdin);
        if (strlen(products[i].name) == 0) {
            printf("Error: Invalid product name!\n");
            return 1;
        }
        products[i].quantity = 0;
        products[i].price = 0.0;
    }

    printf("Enter the quantity of each product: ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &products[i].quantity);
        if (products[i].quantity < 0) {
            printf("Error: Invalid quantity!\n");
            return 1;
        }
    }

    printf("Enter the price of each product: ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%lf", &products[i].price);
        if (products[i].price <= 0.0) {
            printf("Error: Invalid price!\n");
            return 1;
        }
    }

    printf("Product inventory system:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%s\t%d\t%lf\n", products[i].name, products[i].quantity, products[i].price);
    }

    return 0;
}