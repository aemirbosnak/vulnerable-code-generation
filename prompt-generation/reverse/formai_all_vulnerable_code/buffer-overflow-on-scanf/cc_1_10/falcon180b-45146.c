//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CATEGORIES 10
#define MAX_PRODUCT_NAME 50
#define MAX_CATEGORY_NAME 20

typedef struct {
    int id;
    char name[MAX_PRODUCT_NAME];
    int quantity;
    float price;
    int category_id;
} Product;

typedef struct {
    int id;
    char name[MAX_CATEGORY_NAME];
} Category;

Category categories[MAX_CATEGORIES];
Product products[MAX_PRODUCTS];

int num_categories = 0;
int num_products = 0;

void add_category() {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Maximum number of categories reached.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);

    num_categories++;
}

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    int category_id;
    printf("Enter category ID: ");
    scanf("%d", &category_id);

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    products[num_products].category_id = category_id;

    num_products++;
}

void view_products_by_category() {
    printf("Enter category ID: ");
    int category_id;
    scanf("%d", &category_id);

    int num_matching_products = 0;

    for (int i = 0; i < num_products; i++) {
        if (products[i].category_id == category_id) {
            printf("\nProduct ID: %d\nProduct Name: %s\nQuantity: %d\nPrice: %.2f\n\n",
                   products[i].id, products[i].name, products[i].quantity, products[i].price);
            num_matching_products++;
        }
    }

    if (num_matching_products == 0) {
        printf("No products found in this category.\n");
    }
}

int main() {
    printf("Welcome to the Warehouse Management System!\n");

    add_category();
    add_category();
    add_category();

    add_product();
    add_product();
    add_product();

    view_products_by_category();

    return 0;
}