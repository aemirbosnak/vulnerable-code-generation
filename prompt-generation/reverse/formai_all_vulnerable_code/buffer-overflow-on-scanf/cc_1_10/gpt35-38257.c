//FormAI DATASET v1.0 Category: Product Inventory System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct Product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];

int numProducts = 0;

void addProduct() {
    if (numProducts == MAX_PRODUCTS) {
        printf("Inventory is full.\n");
    } else {
        Product newProduct;

        printf("Enter product name: ");
        scanf("%s", newProduct.name);

        printf("Enter product quantity: ");
        scanf("%d", &newProduct.quantity);

        printf("Enter product price: ");
        scanf("%f", &newProduct.price);

        products[numProducts++] = newProduct;
    }
}

void removeProduct() {
    char productName[MAX_NAME_LENGTH];

    printf("Enter product name to remove: ");
    scanf("%s", productName);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }

            numProducts--;

            printf("%s removed from inventory.\n", productName);

            return;
        }
    }

    printf("%s not found in inventory.\n", productName);
}

void displayInventory() {
    printf("\n========= INVENTORY =========\n\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%d. %s x%d $%.2f\n", i + 1, products[i].name, products[i].quantity, products[i].price);
    }

    printf("\n=============================\n\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n========= MAIN MENU =========\n\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}