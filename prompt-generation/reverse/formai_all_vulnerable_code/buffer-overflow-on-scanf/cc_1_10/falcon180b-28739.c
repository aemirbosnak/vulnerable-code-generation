//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    char name[50];
    int id;
    float price;
    int quantity;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    // Initialize the product array
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i].id = -1;
        products[i].price = 0;
        products[i].quantity = 0;
    }

    // Add a product
    char name[50];
    int id;
    float price;
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product ID: ");
    scanf("%d", &id);

    printf("Enter product price: ");
    scanf("%f", &price);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == -1) {
            products[i].id = id;
            products[i].name[0] = '\0';
            strcat(products[i].name, name);
            products[i].price = price;
            products[i].quantity = quantity;
            num_products++;
            break;
        }
    }

    // Display products
    printf("\nProduct List:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    return 0;
}