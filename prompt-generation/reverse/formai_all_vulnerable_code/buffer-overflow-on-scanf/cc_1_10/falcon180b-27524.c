//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_PRICE_LENGTH 10
#define MAX_QUANTITY_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char price[MAX_PRICE_LENGTH];
    int quantity;
} Product;

int num_products = 0;
Product products[MAX_PRODUCTS];

void add_product() {
    printf("Enter product name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", products[num_products].name);

    printf("Enter product description (up to %d characters): ", MAX_DESCRIPTION_LENGTH - 1);
    scanf("%s", products[num_products].description);

    printf("Enter product price (up to %d characters): ", MAX_PRICE_LENGTH - 1);
    scanf("%s", products[num_products].price);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    num_products++;
}

void display_products() {
    printf("Product Inventory\n");
    printf("-----------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %s - $%.2f - %d\n", i+1, products[i].name, products[i].description, atof(products[i].price), products[i].quantity);
    }
}

int main() {
    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Exit\n");

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
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}