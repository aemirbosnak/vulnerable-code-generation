//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void addProduct() {
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

void removeProduct() {
    if (num_products == 0) {
        printf("Error: No products in inventory.\n");
        return;
    }

    printf("Enter product name to remove: ");
    scanf("%s", products[num_products - 1].name);

    for (int i = 0; i < num_products - 1; i++) {
        strcpy(products[i].name, products[i + 1].name);
        products[i].quantity = products[i + 1].quantity;
    }

    num_products--;
}

void updateProduct() {
    if (num_products == 0) {
        printf("Error: No products in inventory.\n");
        return;
    }

    printf("Enter product name to update: ");
    scanf("%s", products[num_products - 1].name);

    printf("Enter new product quantity: ");
    scanf("%d", &products[num_products - 1].quantity);
}

void displayInventory() {
    printf("Product Inventory:\n");
    printf("----------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s - %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    int choice;

    do {
        printf("Product Inventory System\n");
        printf("---------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}