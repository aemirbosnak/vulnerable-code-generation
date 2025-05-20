//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    char name[MAX_NAME_LENGTH];
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].quantity += quantity;
            printf("Product '%s' quantity updated.\n", name);
            return;
        }
    }

    if (num_products >= MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    num_products++;

    printf("Product '%s' added.\n", name);
}

void remove_product() {
    char name[MAX_NAME_LENGTH];

    printf("Enter product name: ");
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i] = products[--num_products];
            printf("Product '%s' removed.\n", name);
            return;
        }
    }

    printf("Product not found.\n");
}

void display_products() {
    printf("Product Inventory:\n");
    printf("-----------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    num_products = 0;

    while (1) {
        printf("\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Exit\n");
        printf("\n");

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
            display_products();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}