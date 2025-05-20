//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 50
#define PRODUCT_NAME_LENGTH 50
#define PRODUCT_QUANTITY_LENGTH 10

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void error_handler(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

void add_product(char *name, int quantity) {
    if (num_products >= MAX_PRODUCTS) {
        error_handler("Inventory is full.\n");
    }

    Product *product = malloc(sizeof(Product));
    if (!product) {
        error_handler("Memory allocation failed.\n");
    }

    strcpy(product->name, name);
    product->quantity = quantity;

    inventory[num_products++] = *product;
}

void remove_product(char *name) {
    int i;
    for (i = 0; i < num_products; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            memmove(&inventory[i], &inventory[i + 1], (num_products - i) * sizeof(Product));
            --num_products;
            free(inventory + num_products);
            break;
        }
    }

    if (i == num_products) {
        error_handler("Product not found.\n");
    }
}

void view_inventory() {
    int i;
    printf("\nCurrent inventory:\n");

    for (i = 0; i < num_products; ++i) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    char name[PRODUCT_NAME_LENGTH];
    int choice, quantity;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. View inventory\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                add_product(name, quantity);
                break;
            case 2:
                printf("Enter product name to remove: ");
                scanf("%s", name);
                remove_product(name);
                break;
            case 3:
                view_inventory();
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}