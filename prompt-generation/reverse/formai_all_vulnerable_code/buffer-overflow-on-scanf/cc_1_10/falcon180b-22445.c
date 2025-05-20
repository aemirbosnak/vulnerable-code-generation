//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 100
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(char* name, int quantity, double price) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    products[num_products].price = price;

    num_products++;
}

void display_products() {
    printf("Product Name\tQuantity\tPrice\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void search_product(char* name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Product found:\n");
            printf("Name: %s\n", products[i].name);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Price: %.2f\n", products[i].price);
            break;
        }
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;

    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter product name: ");
            scanf("%s", name);

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            printf("Enter price: ");
            scanf("%lf", &price);

            add_product(name, quantity, price);
            break;

        case 2:
            display_products();
            break;

        case 3:
            printf("Enter product name to search: ");
            scanf("%s", name);

            search_product(name);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}