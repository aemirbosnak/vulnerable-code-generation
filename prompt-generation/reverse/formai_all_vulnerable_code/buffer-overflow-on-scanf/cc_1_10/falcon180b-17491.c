//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    int numProducts;
    Product products[MAX_PRODUCTS];
    char input[MAX_NAME_LENGTH];
    int i, j;

    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    for (i = 0; i < numProducts; i++) {
        printf("\nEnter product details for product %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Description: ");
        scanf("%s", products[i].description);
        printf("Category: ");
        scanf("%s", products[i].category);
        printf("Quantity: ");
        scanf("%d", &products[i].quantity);
        printf("Price: ");
        scanf("%f", &products[i].price);
    }

    printf("\nProduct Inventory:\n");
    printf("--------------------\n");
    printf("Name\tDescription\tCategory\tQuantity\tPrice\n");

    for (i = 0; i < numProducts; i++) {
        printf("%s\t%s\t%s\t%d\t%.2f\n", products[i].name, products[i].description, products[i].category, products[i].quantity, products[i].price);
    }

    return 0;
}