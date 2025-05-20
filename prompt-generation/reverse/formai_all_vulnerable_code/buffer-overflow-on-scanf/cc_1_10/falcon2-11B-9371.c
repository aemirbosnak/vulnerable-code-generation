//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

struct Product {
    int id;
    char name[50];
    int price;
    int quantity;
};

void print_product(struct Product *product) {
    printf("ID: %d, Name: %s, Price: %d, Quantity: %d\n", product->id, product->name, product->price, product->quantity);
}

void add_product(struct Product *products, int quantity) {
    struct Product *new_product = malloc(sizeof(struct Product));
    if (new_product == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter product ID: ");
    scanf("%d", &new_product->id);
    printf("Enter product name: ");
    scanf("%s", new_product->name);
    printf("Enter product price: ");
    scanf("%d", &new_product->price);
    new_product->quantity = quantity;
    printf("Product added successfully\n");
    products = realloc(products, (sizeof(struct Product) * (products->quantity + 1)));
    if (products == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    products[products->quantity] = *new_product;
}

int main() {
    struct Product *products = malloc(sizeof(struct Product));
    if (products == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter initial product ID: ");
    scanf("%d", &products->id);
    printf("Enter initial product name: ");
    scanf("%s", products->name);
    printf("Enter initial product price: ");
    scanf("%d", &products->price);
    printf("Enter initial product quantity: ");
    scanf("%d", &products->quantity);
    print_product(products);
    add_product(products, 10);
    print_product(products);
    return 0;
}