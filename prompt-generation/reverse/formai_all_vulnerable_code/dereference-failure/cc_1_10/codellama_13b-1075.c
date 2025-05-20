//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 32
#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int price;
    int quantity;
} Product;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int product_count;
    Product* products[MAX_PRODUCTS];
} Category;

void add_product(Category* category, Product* product) {
    if (category->product_count < MAX_PRODUCTS) {
        category->products[category->product_count] = product;
        category->product_count++;
    }
}

void remove_product(Category* category, Product* product) {
    for (int i = 0; i < category->product_count; i++) {
        if (category->products[i] == product) {
            category->products[i] = category->products[category->product_count - 1];
            category->product_count--;
            break;
        }
    }
}

void print_products(Category* category) {
    printf("Category: %s\n", category->name);
    for (int i = 0; i < category->product_count; i++) {
        Product* product = category->products[i];
        printf("Product: %s\n", product->name);
        printf("Price: %d\n", product->price);
        printf("Quantity: %d\n", product->quantity);
    }
}

int main() {
    Category* categories[MAX_CATEGORIES];
    int category_count = 0;

    Category* electronics = malloc(sizeof(Category));
    strcpy(electronics->name, "Electronics");
    electronics->product_count = 0;

    Product* smartphone = malloc(sizeof(Product));
    strcpy(smartphone->name, "Smartphone");
    smartphone->price = 1000;
    smartphone->quantity = 10;

    Product* tablet = malloc(sizeof(Product));
    strcpy(tablet->name, "Tablet");
    tablet->price = 800;
    tablet->quantity = 5;

    add_product(electronics, smartphone);
    add_product(electronics, tablet);

    categories[category_count++] = electronics;

    Category* clothing = malloc(sizeof(Category));
    strcpy(clothing->name, "Clothing");
    clothing->product_count = 0;

    Product* tshirt = malloc(sizeof(Product));
    strcpy(tshirt->name, "T-Shirt");
    tshirt->price = 20;
    tshirt->quantity = 100;

    Product* jeans = malloc(sizeof(Product));
    strcpy(jeans->name, "Jeans");
    jeans->price = 30;
    jeans->quantity = 50;

    add_product(clothing, tshirt);
    add_product(clothing, jeans);

    categories[category_count++] = clothing;

    for (int i = 0; i < category_count; i++) {
        print_products(categories[i]);
    }

    remove_product(clothing, jeans);

    for (int i = 0; i < category_count; i++) {
        print_products(categories[i]);
    }

    return 0;
}