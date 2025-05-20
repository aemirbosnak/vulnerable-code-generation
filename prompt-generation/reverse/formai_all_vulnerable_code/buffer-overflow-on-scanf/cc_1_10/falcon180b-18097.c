//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} product;

product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product category: ");
    scanf("%s", products[num_products].category);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
    printf("Product added successfully.\n");
}

void view_products() {
    printf("Product Name | Category | Quantity | Price\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%-50s | %-20s | %10d | $%.2f\n", products[i].name, products[i].category, products[i].quantity, products[i].price);
    }
}

void search_product() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("Product found:\n");
            printf("Product Name: %s\n", products[i].name);
            printf("Product Category: %s\n", products[i].category);
            printf("Product Quantity: %d\n", products[i].quantity);
            printf("Product Price: $%.2f\n", products[i].price);
        }
    }
}

int main() {
    add_product();
    add_product();
    add_product();

    view_products();

    search_product();

    return 0;
}