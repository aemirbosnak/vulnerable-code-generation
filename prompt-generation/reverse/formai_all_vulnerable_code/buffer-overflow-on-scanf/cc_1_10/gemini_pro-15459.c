//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int quantity;
    float price;
} product;

product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(product p) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }

    inventory[num_products] = p;
    num_products++;
}

void remove_product(int id) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }

    if (i == num_products) {
        printf("Error: Product not found.\n");
        return;
    }

    for (; i < num_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    num_products--;
}

void update_product(int id, product p) {
    int i;

    for (i = 0; i < num_products; i++) {
        if (inventory[i].id == id) {
            break;
        }
    }

    if (i == num_products) {
        printf("Error: Product not found.\n");
        return;
    }

    inventory[i] = p;
}

void print_inventory() {
    int i;

    for (i = 0; i < num_products; i++) {
        printf("Product %d:\n", inventory[i].id);
        printf("  Name: %s\n", inventory[i].name);
        printf("  Description: %s\n", inventory[i].description);
        printf("  Quantity: %d\n", inventory[i].quantity);
        printf("  Price: %.2f\n", inventory[i].price);
    }
}

int main() {
    int choice;
    product p;

    while (1) {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Print inventory\n");
        printf("5. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product ID: ");
                scanf("%d", &p.id);

                printf("Enter product name: ");
                scanf("%s", p.name);

                printf("Enter product description: ");
                scanf("%s", p.description);

                printf("Enter product quantity: ");
                scanf("%d", &p.quantity);

                printf("Enter product price: ");
                scanf("%f", &p.price);

                add_product(p);
                break;

            case 2:
                printf("Enter product ID to remove: ");
                scanf("%d", &p.id);

                remove_product(p.id);
                break;

            case 3:
                printf("Enter product ID to update: ");
                scanf("%d", &p.id);

                printf("Enter new product name: ");
                scanf("%s", p.name);

                printf("Enter new product description: ");
                scanf("%s", p.description);

                printf("Enter new product quantity: ");
                scanf("%d", &p.quantity);

                printf("Enter new product price: ");
                scanf("%f", &p.price);

                update_product(p.id, p);
                break;

            case 4:
                print_inventory();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}