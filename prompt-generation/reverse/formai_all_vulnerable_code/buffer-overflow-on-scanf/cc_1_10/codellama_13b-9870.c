//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
/*
 * Product Inventory System
 *
 * This program is a simple inventory management system that allows
 * the user to add, remove, and modify products in a database.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[256];
    int quantity;
    float price;
} Product;

void add_product(Product *products, int *num_products) {
    printf("Enter product name: ");
    scanf("%s", products[*num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*num_products].price);
    (*num_products)++;
}

void remove_product(Product *products, int *num_products) {
    printf("Enter product name to remove: ");
    char name[256];
    scanf("%s", name);
    int i;
    for (i = 0; i < *num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i] = products[*num_products - 1];
            (*num_products)--;
            break;
        }
    }
}

void modify_product(Product *products, int *num_products) {
    printf("Enter product name to modify: ");
    char name[256];
    scanf("%s", name);
    int i;
    for (i = 0; i < *num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
            break;
        }
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char choice;

    while (1) {
        printf("A)dd product\n");
        printf("R)emove product\n");
        printf("M)odify product\n");
        printf("Q)uit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
                add_product(products, &num_products);
                break;
            case 'R':
                remove_product(products, &num_products);
                break;
            case 'M':
                modify_product(products, &num_products);
                break;
            case 'Q':
                return 0;
        }
    }

    return 0;
}