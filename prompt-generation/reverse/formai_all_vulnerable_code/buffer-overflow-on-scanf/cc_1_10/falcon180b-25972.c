//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_PRICE_LEN 10

struct product {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
};

void addProduct(struct product *products, int size, int *index) {
    printf("Enter product name: ");
    scanf("%s", products[*index].name);
    printf("Enter product description: ");
    scanf("%s", products[*index].description);
    printf("Enter product price: ");
    scanf("%s", products[*index].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[*index].quantity);
    (*index)++;
}

void printProduct(struct product product) {
    printf("Product Name: %s\n", product.name);
    printf("Product Description: %s\n", product.description);
    printf("Product Price: $%.2f\n", atof(product.price));
    printf("Product Quantity: %d\n", product.quantity);
}

void viewInventory(struct product *products, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printProduct(products[i]);
    }
}

int main() {
    struct product products[MAX_PRODUCTS];
    int size = 0;
    int index = 0;

    printf("Welcome to the Product Inventory System!\n");

    while (size < MAX_PRODUCTS) {
        printf("\nEnter 1 to add a product or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addProduct(products, size, &index);
            size++;
        } else if (choice!= 0) {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("\nInventory:\n");
    viewInventory(products, size);

    return 0;
}