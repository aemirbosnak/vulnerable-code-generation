//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product description: ");
    scanf("%s", products[num_products].description);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    num_products++;
}

void display_products() {
    printf("Product Name\tProduct Description\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%s\t\t%d\t\t$%0.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }
}

int main() {
    num_products = 0;

    while (1) {
        printf("\nProduct Inventory System\n");
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
                printf("Invalid choice\n");
        }
    }

    return 0;
}