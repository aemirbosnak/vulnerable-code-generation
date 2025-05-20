//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Cannot add more products.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);

    num_products++;
}

void remove_product() {
    if (num_products == 0) {
        printf("Error: No products to remove.\n");
        return;
    }

    printf("Enter product name to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            printf("Removing product '%s'\n", products[i].name);
            num_products--;
            return;
        }
    }

    printf("Product not found.\n");
}

void update_product() {
    if (num_products == 0) {
        printf("Error: No products to update.\n");
        return;
    }

    printf("Enter product name to update: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            printf("Enter new product name: ");
            scanf("%s", products[i].name);

            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Enter new product price: ");
            scanf("%lf", &products[i].price);

            printf("Product '%s' updated.\n", products[i].name);
            return;
        }
    }

    printf("Product not found.\n");
}

void list_products() {
    if (num_products == 0) {
        printf("No products found.\n");
        return;
    }

    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%d\t%.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    printf("Product Inventory System\n");

    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. List products\n");
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
                update_product();
                break;
            case 4:
                list_products();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}