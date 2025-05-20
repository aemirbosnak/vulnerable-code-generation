//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

int num_products = 0;
Product products[MAX_PRODUCTS];

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
    num_products++;
}

void view_products() {
    printf("Product ID | Product Name | Description | Quantity | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %s | %d | $%.2f\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

void update_product() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    printf("Enter new product name: ");
    scanf("%s", products[id-1].name);
    printf("Enter new product description: ");
    scanf("%s", products[id-1].description);
    printf("Enter new product quantity: ");
    scanf("%d", &products[id-1].quantity);
    printf("Enter new product price: ");
    scanf("%lf", &products[id-1].price);
}

void delete_product() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    for (int i = id-1; i < num_products-1; i++) {
        products[i] = products[i+1];
    }
    num_products--;
}

int main() {
    add_product();
    add_product();
    add_product();
    view_products();
    update_product();
    delete_product();
    view_products();
    return 0;
}