//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: statistical
// C Product Inventory System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000 // Maximum number of products
#define MAX_NAME_LENGTH 50 // Maximum length of product name
#define MAX_QUANTITY 1000 // Maximum quantity of a product

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} product;

product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);

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
        if (strcmp(products[i].name, name) == 0) {
            memmove(&products[i], &products[i+1], sizeof(product) * (num_products - i - 1));
            num_products--;
            break;
        }
    }
}

void display_products() {
    if (num_products == 0) {
        printf("No products found.\n");
        return;
    }

    printf("Product Name\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    int choice;

    do {
        printf("Product Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}

// End of C Product Inventory System