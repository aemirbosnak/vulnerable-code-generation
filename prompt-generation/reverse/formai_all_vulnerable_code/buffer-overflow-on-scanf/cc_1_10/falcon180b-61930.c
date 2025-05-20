//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 100
#define MAX_PRICE 100000

typedef struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} product_t;

void add_product(product_t *products, int num_products) {
    printf("Enter product name: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);

    strcpy(products[num_products].name, name);
    num_products++;
}

void display_products(product_t *products, int num_products) {
    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-50s\t%d\t%.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    product_t products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter 1 to add a product, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            add_product(products, num_products);
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Product Inventory:\n");
    display_products(products, num_products);

    return 0;
}