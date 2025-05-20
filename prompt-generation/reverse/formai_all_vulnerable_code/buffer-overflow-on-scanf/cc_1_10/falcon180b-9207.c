//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 9999.99

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} product_t;

void add_product(product_t* products, int num_products) {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product category: ");
    scanf("%s", products[num_products].category);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
}

void display_products(product_t* products, int num_products) {
    printf("Product ID | Product Name | Category | Description | Quantity | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %s | %s | %d | $%.2lf\n", i+1, products[i].name, products[i].category, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    product_t products[MAX_PRODUCTS];
    int num_products = 0;

    printf("Welcome to the product inventory system!\n\n");

    while (num_products < MAX_PRODUCTS) {
        printf("What would you like to do?\n");
        printf("1. Add a product\n");
        printf("2. Display products\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(products, num_products);
                num_products++;
                break;
            case 2:
                display_products(products, num_products);
                break;
            case 3:
                printf("Thank you for using the product inventory system!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}