//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char category[MAX_CATEGORY_LEN];
    char price[MAX_PRICE_LEN];
    char quantity[MAX_QUANTITY_LEN];
} Product;

int main() {
    int num_products;
    Product products[MAX_PRODUCTS];
    char input[100];
    int i;

    // Read in the number of products
    printf("Enter the number of products: ");
    scanf("%d", &num_products);

    // Read in the product information
    for (i = 0; i < num_products; i++) {
        printf("Enter product information for product #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Description: ");
        scanf("%s", products[i].description);
        printf("Category: ");
        scanf("%s", products[i].category);
        printf("Price: ");
        scanf("%s", products[i].price);
        printf("Quantity: ");
        scanf("%s", products[i].quantity);
    }

    // Print out the product information
    printf("\nProduct Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("Product #%d:\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("Description: %s\n", products[i].description);
        printf("Category: %s\n", products[i].category);
        printf("Price: %s\n", products[i].price);
        printf("Quantity: %s\n\n", products[i].quantity);
    }

    return 0;
}