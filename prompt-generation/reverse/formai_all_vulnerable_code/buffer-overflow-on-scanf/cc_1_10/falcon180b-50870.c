//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

struct product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
};

void add_product(struct product *products, int num_products) {
    printf("Enter product name: ");
    scanf("%s", &products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", &products[num_products].description);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
}

void display_products(struct product *products, int num_products) {
    printf("Product Name\tProduct Description\tQuantity\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s\t%s\t%d\t$%.2lf\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter 1 to add a product, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_product(products, num_products);
            num_products++;
        } else if (choice!= 0) {
            printf("Invalid input. Please try again.\n");
        }
    }

    display_products(products, num_products);

    return 0;
}