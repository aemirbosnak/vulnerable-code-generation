//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 9999

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    products[num_products].quantity = 0;
    num_products++;
}

void remove_product() {
    if (num_products == 0) {
        printf("Error: No products to remove.\n");
        return;
    }

    printf("Enter product name to remove: ");
    scanf("%s", products[0].name);

    for (int i = 1; i < num_products; i++) {
        strcpy(products[i-1].name, products[i].name);
        products[i-1].quantity = products[i].quantity;
    }

    num_products--;
}

void display_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d units\n", products[i].name, products[i].quantity);
    }
}

void update_quantity() {
    printf("Enter product name to update: ");
    scanf("%s", products[0].name);

    for (int i = 1; i < num_products; i++) {
        if (strcmp(products[i].name, products[0].name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            break;
        }
    }
}

int main() {
    add_product();
    add_product();
    display_products();
    update_quantity();
    display_products();
    remove_product();
    display_products();

    return 0;
}