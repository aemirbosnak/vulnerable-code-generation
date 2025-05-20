//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    char category[20];
    int quantity;
    float price;
} Product;

typedef struct {
    char name[20];
    int num_products;
    Product products[MAX_PRODUCTS];
} Category;

void read_products(Product products[], int num_products) {
    FILE *fp = fopen("products.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open products file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %d %f", products[i].name, products[i].category, &products[i].quantity, &products[i].price) == 4 && i < num_products) {
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
    while (fscanf(fp, "%s %d", categories[i].name, &categories[i].num_products) == 2 && i < num_categories) {
        i++;
    }

    fclose(fp);
}

void print_products(Product products[], int num_products) {
    printf("Product Name | Category | Quantity | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-20s %4d $ %7.2f\n", products[i].name, products[i].category, products[i].quantity, products[i].price);
    }
}

void print_categories(Category categories[], int num_categories) {
    printf("Category Name | Number of Products\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%-20s %4d\n", categories[i].name, categories[i].num_products);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    Category categories[MAX_CATEGORIES];

    read_products(products, MAX_PRODUCTS);
    read_categories(categories, MAX_CATEGORIES);

    print_products(products, MAX_PRODUCTS);
    print_categories(categories, MAX_CATEGORIES);

    return 0;
}