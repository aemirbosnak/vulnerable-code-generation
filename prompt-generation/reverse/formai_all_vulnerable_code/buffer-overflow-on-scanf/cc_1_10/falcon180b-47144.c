//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &products[num_products].id);

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", products[num_products].description);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    num_products++;
}

void display_products() {
    printf("Product ID | Product Name | Product Description | Product Price | Product Quantity\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d | %s | %s | $%.2f | %d\n",
                products[i].id, products[i].name, products[i].description, products[i].price, products[i].quantity);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("1. Add product\n2. Display products\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}