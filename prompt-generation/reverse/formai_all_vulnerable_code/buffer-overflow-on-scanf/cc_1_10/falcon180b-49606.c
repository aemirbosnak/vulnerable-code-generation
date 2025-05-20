//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_QUANTITY_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char quantity[MAX_QUANTITY_LEN];
    char price[MAX_PRICE_LEN];
    int quantity_on_hand;
    float price_per_unit;
} Product;

void add_product(Product* products, int num_products) {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product category: ");
    scanf("%s", products[num_products].category);

    printf("Enter product quantity: ");
    scanf("%s", products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%s", products[num_products].price);

    products[num_products].quantity_on_hand = atoi(products[num_products].quantity);
    products[num_products].price_per_unit = atof(products[num_products].price);
}

void print_products(Product* products, int num_products) {
    printf("Product Name | Category | Quantity On Hand | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-50s | %-50s | %10d | $%8.2f\n", products[i].name, products[i].category, products[i].quantity_on_hand, products[i].price_per_unit);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter product information:\n");
        add_product(products, num_products);
        num_products++;
    }

    printf("Product Inventory:\n");
    print_products(products, num_products);

    return 0;
}