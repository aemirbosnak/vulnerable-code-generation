//FormAI DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

struct inventory {
    struct product products[MAX_PRODUCTS];
    int count;
} inventory;

int add_product(char *name, int quantity, float price) {
    if (inventory.count >= MAX_PRODUCTS) {
        printf("Error: Inventory full\n");
        return 1;
    }

    struct product new_product;

    strncpy(new_product.name, name, MAX_NAME_LENGTH);
    new_product.quantity = quantity;
    new_product.price = price;

    inventory.products[inventory.count] = new_product;
    inventory.count++;

    printf("New product added to inventory.\n");

    return 0;
}

int remove_product(char *name) {
    int i;
    int found = 0;

    for (i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.products[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Product not found\n");
        return 1;
    }

    inventory.products[i] = inventory.products[inventory.count - 1];
    inventory.count--;

    printf("Product removed from inventory.\n");

    return 0;
}

int update_product(char *name, int quantity, float price) {
    int i;
    int found = 0;

    for (i = 0; i < inventory.count; i++) {
        if (strcmp(inventory.products[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Product not found\n");
        return 1;
    }

    inventory.products[i].quantity = quantity;
    inventory.products[i].price = price;

    printf("Product updated in inventory.\n");

    return 0;
}

void display_all_products() {
    printf("Products in inventory:\n");

    int i;
    for (i = 0; i < inventory.count; i++) {
        printf("[%d] Name: %s, Quantity: %d, Price: $%.2f\n", i + 1, inventory.products[i].name, inventory.products[i].quantity, inventory.products[i].price);
    }
}

int main() {
    int choice = -1;

    while (choice != 0) {
        printf("\nInventory System Menu\n");
        printf("[1] Add Product\n");
        printf("[2] Remove Product\n");
        printf("[3] Update Product\n");
        printf("[4] Display All Products\n");
        printf("[0] Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                int quantity;
                float price;

                printf("Enter product name: ");
                scanf("%s", name);

                printf("Enter product quantity: ");
                scanf("%d", &quantity);

                printf("Enter product price: ");
                scanf("%f", &price);

                add_product(name, quantity, price);
                break;
            }
            case 2: {
                char name[MAX_NAME_LENGTH];

                printf("Enter product name: ");
                scanf("%s", name);

                remove_product(name);
                break;
            }
            case 3: {
                char name[MAX_NAME_LENGTH];
                int quantity;
                float price;

                printf("Enter product name: ");
                scanf("%s", name);

                printf("Enter updated product quantity: ");
                scanf("%d", &quantity);

                printf("Enter updated product price: ");
                scanf("%f", &price);

                update_product(name, quantity, price);
                break;
            }
            case 4: {
                display_all_products();
                break;
            }
            case 0: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice, please try again.\n");
                break;
            }
        }
    }

    return 0;
}