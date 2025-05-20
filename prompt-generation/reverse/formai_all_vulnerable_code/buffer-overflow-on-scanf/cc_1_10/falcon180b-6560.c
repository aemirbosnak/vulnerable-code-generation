//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 10000.00

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char input[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;

    printf("Enter product name: ");
    scanf("%s", input);

    while (num_products < MAX_PRODUCTS) {
        printf("Enter product description: ");
        scanf("%s", description);

        printf("Enter product quantity: ");
        scanf("%d", &quantity);

        printf("Enter product price: ");
        scanf("%f", &price);

        strcpy(products[num_products].name, input);
        strcpy(products[num_products].description, description);
        products[num_products].quantity = quantity;
        products[num_products].price = price;

        num_products++;

        printf("Do you want to add another product? (y/n): ");
        scanf(" %c", &input[0]);
        if (input[0]!= 'y') {
            break;
        }
    }

    printf("\nProduct Inventory:\n");
    printf("Name\tDescription\tQuantity\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s\t%s\t%d\t$%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    return 0;
}