//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int quantity;
    float price;
    char category[10];
} Product;

typedef struct {
    char name[10];
    int num_products;
} Category;

void read_products(Product products[]) {
    FILE *fp;
    char filename[50];
    int i = 0;

    sprintf(filename, "products.txt");
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening products file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %f %s", products[i].name, &products[i].quantity, &products[i].price, products[i].category)!= EOF) {
        i++;
    }

    fclose(fp);
}

void read_categories(Category categories[]) {
    FILE *fp;
    char filename[50];
    int i = 0;

    sprintf(filename, "categories.txt");
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening categories file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", categories[i].name, &categories[i].num_products)!= EOF) {
        i++;
    }

    fclose(fp);
}

void display_products(Product products[]) {
    int i;

    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].quantity > 0) {
            printf("%s - %d units - $%.2f - %s\n", products[i].name, products[i].quantity, products[i].price, products[i].category);
        }
    }
}

void display_categories(Category categories[]) {
    int i;

    for (i = 0; i < MAX_CATEGORIES; i++) {
        printf("%s - %d products\n", categories[i].name, categories[i].num_products);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    Category categories[MAX_CATEGORIES];

    read_products(products);
    read_categories(categories);

    display_products(products);
    display_categories(categories);

    return 0;
}