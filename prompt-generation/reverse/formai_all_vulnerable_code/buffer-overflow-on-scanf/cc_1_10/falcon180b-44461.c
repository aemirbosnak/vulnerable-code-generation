//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

struct product {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
};

int main() {
    int num_products;
    struct product products[MAX_PRODUCTS];

    // Get number of products from user
    printf("Enter number of products: ");
    scanf("%d", &num_products);

    // Read product data from user
    for (int i = 0; i < num_products; i++) {
        printf("Enter product name: ");
        scanf("%s", products[i].name);

        printf("Enter product description: ");
        scanf("%s", products[i].description);

        printf("Enter product quantity: ");
        scanf("%d", &products[i].quantity);

        printf("Enter product price: ");
        scanf("%lf", &products[i].price);
    }

    // Display product inventory
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("Product %d:\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2lf\n\n", products[i].price);
    }

    return 0;
}