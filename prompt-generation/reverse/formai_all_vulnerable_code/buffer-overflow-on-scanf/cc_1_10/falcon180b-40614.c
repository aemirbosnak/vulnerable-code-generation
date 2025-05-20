//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Too many products.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", products[num_products].description);

    printf("Enter product price: ");
    scanf("%d", &products[num_products].price);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    num_products++;
}

void view_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %s - $%d (Quantity: %d)\n", i+1, products[i].name, products[i].description, products[i].price, products[i].quantity);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add product\n");
        printf("2. View products\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                view_products();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}