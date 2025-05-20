//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
    int category;
} Product;

typedef struct {
    char name[50];
    int num_products;
} Category;

void read_products(Product products[]) {
    FILE *fp;
    fp = fopen("products.txt", "r");

    int i = 0;
    while (fscanf(fp, "%s %d %f %d\n", products[i].name, &products[i].quantity, &products[i].price, &products[i].category)!= EOF) {
        i++;
    }

    fclose(fp);
}

void read_categories(Category categories[]) {
    FILE *fp;
    fp = fopen("categories.txt", "r");

    int i = 0;
    while (fscanf(fp, "%s %d\n", categories[i].name, &categories[i].num_products)!= EOF) {
        i++;
    }

    fclose(fp);
}

void display_products(Product products[]) {
    int i;

    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (products[i].name[0]!= '\0') {
            printf("%s %d $%.2f Category %d\n", products[i].name, products[i].quantity, products[i].price, products[i].category);
        }
    }
}

void display_categories(Category categories[]) {
    int i;

    for (i = 0; i < MAX_CATEGORIES; i++) {
        if (categories[i].name[0]!= '\0') {
            printf("%s (%d products)\n", categories[i].name, categories[i].num_products);
        }
    }
}

void main() {
    Product products[MAX_PRODUCTS];
    Category categories[MAX_CATEGORIES];

    read_products(products);
    read_categories(categories);

    display_products(products);
    display_categories(categories);
}