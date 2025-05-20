//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 20

struct Product {
    char name[MAX_NAME_LEN + 1];
    int quantity;
    float price;
};

struct Inventory {
    int num_products;
    struct Product products[MAX_PRODUCTS];
};

void add_product(struct Inventory *inventory, struct Product product) {
    if (inventory->num_products < MAX_PRODUCTS) {
        inventory->products[inventory->num_products] = product;
        inventory->num_products++;
        printf("Added product %s with quantity %d and price %.2f\n", product.name, product.quantity, product.price);
    } else {
        printf("Inventory is full!\n");
    }
}

void remove_product(struct Inventory *inventory, char *name) {
    int i;
    for (i = 0; i < inventory->num_products; i++) {
        if (strcmp(inventory->products[i].name, name) == 0) {
            printf("Removed product %s\n", inventory->products[i].name);
            inventory->num_products--;
            for (; i < inventory->num_products; i++) {
                inventory->products[i] = inventory->products[i + 1];
            }
            return;
        }
    }
    printf("Product %s not found!\n", name);
}

void list_products(struct Inventory *inventory) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < inventory->num_products; i++) {
        printf("%s - %d - $%.2f\n", inventory->products[i].name, inventory->products[i].quantity, inventory->products[i].price);
    }
}

int main() {
    struct Inventory inventory = {0};

    printf("Welcome to the Product Inventory System!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. List all products\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Product product;
                printf("Enter product name (max %d characters): ", MAX_NAME_LEN);
                scanf("%s", product.name);
                printf("Enter quantity: ");
                scanf("%d", &product.quantity);
                printf("Enter price: ");
                scanf("%f", &product.price);
                add_product(&inventory, product);
                break;
            }
            case 2: {
                char name[MAX_NAME_LEN + 1];
                printf("Enter product name to remove: ");
                scanf("%s", name);
                remove_product(&inventory, name);
                break;
            }
            case 3: {
                list_products(&inventory);
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}