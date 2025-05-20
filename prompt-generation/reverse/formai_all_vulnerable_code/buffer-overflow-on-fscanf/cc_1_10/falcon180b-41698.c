//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char *name;
    int quantity;
    float price;
    int category;
} Product;

typedef struct {
    char *name;
    int num_products;
} Category;

void read_products(Product products[], int num_products) {
    FILE *fp = fopen("products.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open products file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %d %f %d\n", products[i].name, &products[i].quantity, &products[i].price, &products[i].category) == 4 && i < num_products) {
        i++;
    }

    fclose(fp);
}

void read_categories(Category categories[], int num_categories) {
    FILE *fp = fopen("categories.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open categories file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %d\n", categories[i].name, &categories[i].num_products) == 2 && i < num_categories) {
        i++;
    }

    fclose(fp);
}

void print_products(Product products[], int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("%s %d %.2f %d\n", products[i].name, products[i].quantity, products[i].price, products[i].category);
    }
}

void print_categories(Category categories[], int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        printf("%s %d\n", categories[i].name, categories[i].num_products);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    Category categories[MAX_CATEGORIES];

    int num_products = 0;
    int num_categories = 0;

    read_products(products, MAX_PRODUCTS);
    num_products = fmin(num_products, MAX_PRODUCTS);

    read_categories(categories, MAX_CATEGORIES);
    num_categories = fmin(num_categories, MAX_CATEGORIES);

    printf("Products:\n");
    print_products(products, num_products);

    printf("\nCategories:\n");
    print_categories(categories, num_categories);

    return 0;
}