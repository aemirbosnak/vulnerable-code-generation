//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10
#define MAX_QUANTITY_LENGTH 5

struct product {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
};

void create_product(struct product* product, const char* name, float price, int quantity) {
    strncpy(product->name, name, MAX_NAME_LENGTH);
    product->price = price;
    product->quantity = quantity;
}

void display_products(struct product products[], int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("%s - $%.2f - %d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
    int num_products = 0;

    while (1) {
        printf("1. Add product\n2. Display products\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                printf("Enter product price: ");
                float price;
                scanf("%f", &price);

                printf("Enter product quantity: ");
                int quantity;
                scanf("%d", &quantity);

                create_product(products + num_products, name, price, quantity);
                num_products++;
                break;
            case 2:
                display_products(products, num_products);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}