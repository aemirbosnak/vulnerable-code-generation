//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];

int num_products = 0;

void add_product() {
    printf("Enter product name (max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void display_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d in stock - $%.2f each\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void search_product() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter product name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, search_name) == 0) {
            printf("Found product: %s\n", products[i].name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    printf("Welcome to the Romantic Product Inventory System!\n");

    add_product();
    add_product();
    add_product();

    display_products();

    search_product();

    return 0;
}