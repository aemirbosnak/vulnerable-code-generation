//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    int product_id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} Product;

void add_product(Product* products, int num_products) {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product description: ");
    scanf("%s", products[num_products].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);
}

void print_products(Product* products, int num_products) {
    printf("Product ID | Name | Description | Quantity | Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %s | %d | %.2lf\n", products[i].product_id, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (num_products < MAX_PRODUCTS) {
        printf("Enter 1 to add a product or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_product(products, num_products);
            num_products++;
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    printf("Product Inventory:\n");
    print_products(products, num_products);

    return 0;
}