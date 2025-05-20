//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 100000
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
    int quantity;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter product name (or 'done' to finish):\n");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        strcpy(products[num_products].name, name);

        printf("Enter product description:\n");
        scanf("%s", products[num_products].description);

        printf("Enter product price:\n");
        scanf("%f", &products[num_products].price);

        printf("Enter product quantity:\n");
        scanf("%d", &products[num_products].quantity);

        num_products++;
    }

    printf("Product inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Price: $%.2f\n", products[i].price);
        printf("Quantity: %d\n\n", products[i].quantity);
    }

    return 0;
}