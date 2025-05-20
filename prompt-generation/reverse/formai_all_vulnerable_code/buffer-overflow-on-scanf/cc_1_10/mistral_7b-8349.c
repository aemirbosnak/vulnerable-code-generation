//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define MAX_PRODUCTS 10
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(const char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        fprintf(stderr, "Inventory is full.\n");
        return;
    }
    strncpy(inventory[num_products].name, name, MAX_NAME_LEN);
    inventory[num_products].quantity = quantity;
    num_products++;
}

void display_inventory() {
    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char product_name[MAX_NAME_LEN];
    int product_quantity;

    while (1) {
        printf("Enter product name (empty to quit): ");
        scanf("%s", product_name);
        if (strlen(product_name) == 0) {
            break;
        }
        printf("Enter product quantity: ");
        scanf("%d", &product_quantity);
        add_product(product_name, product_quantity);
    }

    printf("\nCurrent inventory:\n");
    display_inventory();

    return 0;
}