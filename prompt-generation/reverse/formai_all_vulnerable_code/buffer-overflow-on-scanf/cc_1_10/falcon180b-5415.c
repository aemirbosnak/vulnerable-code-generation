//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
// Ada Lovelace Style Product Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void add_product() {
    char name[MAX_NAME_LEN];
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            products[i].quantity += quantity;
            printf("Product '%s' already exists. Quantity updated.\n", name);
            return;
        }
    }

    products[num_products] = (Product) {
       .name = strdup(name),
       .quantity = quantity
    };

    num_products++;

    printf("Product '%s' added.\n", name);
}

void remove_product() {
    char name[MAX_NAME_LEN];

    printf("Enter product name: ");
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            free(products[i].name);
            printf("Product '%s' removed.\n", name);
            return;
        }
    }

    printf("Product '%s' not found.\n", name);
}

void update_quantity() {
    char name[MAX_NAME_LEN];
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &quantity);

            products[i].quantity = quantity;

            printf("Product '%s' quantity updated.\n", name);
            return;
        }
    }

    printf("Product '%s' not found.\n", name);
}

void display_products() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    num_products = 0;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update quantity\n");
        printf("4. Display products\n");
        printf("5. Exit\n");

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
            update_quantity();
            break;

        case 4:
            display_products();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}