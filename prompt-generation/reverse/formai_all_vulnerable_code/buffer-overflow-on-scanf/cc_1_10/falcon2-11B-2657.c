//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

typedef struct product_s {
    char name[MAX_NAME_LENGTH];
    int price;
    int quantity;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    printf("Welcome to the Product Inventory System!\n");
    printf("What is the name of the product?\n");
    fgets(products[num_products].name, MAX_NAME_LENGTH, stdin);
    printf("What is the price of the product?\n");
    scanf("%d", &products[num_products].price);
    printf("What is the quantity of the product?\n");
    scanf("%d", &products[num_products].quantity);
    num_products++;

    while (num_products < MAX_PRODUCTS) {
        printf("Do you want to add another product? (y/n)\n");
        char input;
        scanf(" %c", &input);
        if (input == 'y') {
            printf("What is the name of the product?\n");
            fgets(products[num_products].name, MAX_NAME_LENGTH, stdin);
            printf("What is the price of the product?\n");
            scanf("%d", &products[num_products].price);
            printf("What is the quantity of the product?\n");
            scanf("%d", &products[num_products].quantity);
            num_products++;
        } else {
            break;
        }
    }

    printf("Your inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Price: %d\n", products[i].price);
        printf("Quantity: %d\n", products[i].quantity);
        printf("\n");
    }

    return 0;
}