//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_CATEGORY_LEN 50
#define MAX_PRICE 1000000

struct product {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char category[MAX_CATEGORY_LEN];
    int price;
    int quantity;
};

void addProduct(struct product* products, int numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[numProducts].name);
    printf("Enter product description: ");
    scanf("%s", products[numProducts].description);
    printf("Enter product category: ");
    scanf("%s", products[numProducts].category);
    printf("Enter product price: ");
    scanf("%d", &products[numProducts].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[numProducts].quantity);
}

void viewProduct(struct product product) {
    printf("Product name: %s\n", product.name);
    printf("Product description: %s\n", product.description);
    printf("Product category: %s\n", product.category);
    printf("Product price: $%d\n", product.price);
    printf("Product quantity: %d\n", product.quantity);
}

void viewProducts(struct product* products, int numProducts) {
    printf("Product inventory:\n");
    for (int i = 0; i < numProducts; i++) {
        viewProduct(products[i]);
    }
}

void searchProduct(struct product* products, int numProducts) {
    char searchName[MAX_NAME_LEN];
    printf("Enter product name to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            viewProduct(products[i]);
        }
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
    int numProducts = 0;

    while (numProducts < MAX_PRODUCTS) {
        printf("Enter 1 to add product, 2 to view products, 3 to search product, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, numProducts);
                numProducts++;
                break;
            case 2:
                viewProducts(products, numProducts);
                break;
            case 3:
                searchProduct(products, numProducts);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}