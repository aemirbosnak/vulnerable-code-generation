//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

void print_product(Product p) {
    printf("Name: %s\n", p.name);
    printf("Description: %s\n", p.description);
    printf("Quantity: %d\n", p.quantity);
    printf("Price: $%.2f\n", p.price);
}

void read_product(Product *p) {
    printf("Enter product name: ");
    scanf("%s", p->name);

    printf("Enter product description: ");
    scanf("%s", p->description);

    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);

    printf("Enter product price: ");
    scanf("%f", &p->price);
}

void main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter product information (name, description, quantity, price):\n");
        read_product(&products[num_products]);
        num_products++;
    }

    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        print_product(products[i]);
    }
}