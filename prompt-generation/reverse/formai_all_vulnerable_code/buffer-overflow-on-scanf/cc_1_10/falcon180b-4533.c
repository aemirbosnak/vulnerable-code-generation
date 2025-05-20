//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 9999.99

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
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

    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter price: ");
    scanf("%lf", &products[num_products].price);

    num_products++;
}

void remove_product() {
    if (num_products <= 0) {
        printf("Error: No products.\n");
        return;
    }

    printf("Enter product name to remove: ");
    scanf("%s", products[num_products - 1].name);

    for (int i = 0; i < num_products - 1; i++) {
        strcpy(products[i].name, products[i + 1].name);
        products[i].quantity = products[i + 1].quantity;
        products[i].price = products[i + 1].price;
    }

    num_products--;
}

void print_products() {
    if (num_products <= 0) {
        printf("Error: No products.\n");
        return;
    }

    for (int i = 0; i < num_products; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: %s\n", products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2lf\n\n", products[i].price);
    }
}

int main() {
    printf("Cyberpunk Product Inventory System\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Print products\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_product();
            break;
        case 2:
            remove_product();
            break;
        case 3:
            print_products();
            break;
        case 4:
            exit(0);
        default:
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}