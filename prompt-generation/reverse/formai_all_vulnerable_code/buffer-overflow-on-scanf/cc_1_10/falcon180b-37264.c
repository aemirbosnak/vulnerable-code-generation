//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRODUCT_DESCRIPTION_LENGTH 100
#define MAX_PRODUCT_QUANTITY 1000
#define MAX_PRODUCT_PRICE 1000.00

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    char description[MAX_PRODUCT_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} product;

void add_product(product *products, int num_products) {
    printf("Enter product name: ");
    scanf("%s", &products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", &products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);
    printf("\n");
}

void view_products(product *products, int num_products) {
    printf("Product List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("Product Name: %s\n", products[i].name);
        printf("Product Description: %s\n", products[i].description);
        printf("Product Quantity: %d\n", products[i].quantity);
        printf("Product Price: $%.2f\n\n", products[i].price);
    }
}

int main() {
    product products[10];
    int num_products = 0;

    printf("Welcome to the Warehouse Management System!\n\n");
    while (1) {
        printf("\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        char choice;
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_products >= 10) {
                    printf("Maximum number of products reached.\n");
                } else {
                    add_product(products, num_products);
                    num_products++;
                }
                break;
            case '2':
                view_products(products, num_products);
                break;
            case '3':
                printf("Thank you for using the Warehouse Management System!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}