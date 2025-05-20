//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_PRICE 10000

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int price;
    int quantity;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter product name (or 'done' to finish): ");
        char name[MAX_NAME_LEN];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter product description: ");
        char description[MAX_DESCRIPTION_LEN];
        scanf("%s", description);

        printf("Enter product price: ");
        int price;
        scanf("%d", &price);

        printf("Enter product quantity: ");
        int quantity;
        scanf("%d", &quantity);

        strcpy(products[num_products].name, name);
        strcpy(products[num_products].description, description);
        products[num_products].price = price;
        products[num_products].quantity = quantity;

        num_products++;
    }

    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%s\t%d\t%d\n", products[i].name, products[i].description, products[i].price, products[i].quantity);
    }

    return 0;
}