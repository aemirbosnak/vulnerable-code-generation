//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    char category[50];
    float price;
    int quantity;
} Product;

void add_product(Product products[], int count) {
    printf("Enter product name: ");
    scanf("%s", products[count].name);

    printf("Enter product category: ");
    scanf("%s", products[count].category);

    printf("Enter product price: ");
    scanf("%f", &products[count].price);

    printf("Enter product quantity: ");
    scanf("%d", &products[count].quantity);

    count++;
}

void display_products(Product products[], int count) {
    printf("\nProduct Name\tProduct Category\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%.2f\t%d\n", products[i].name, products[i].category, products[i].price, products[i].quantity);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;

    add_product(products, count);

    while (1) {
        display_products(products, count);

        printf("\nDo you want to add more products? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'n') {
            break;
        }

        add_product(products, count);
    }

    return 0;
}