//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

struct Product {
    char name[MAX_NAME_LEN];
    char description[MAX_NAME_LEN];
    float price;
};

struct Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(const char* name, const char* description, float price) {
    if (numProducts == MAX_PRODUCTS) {
        fprintf(stderr, "Inventory is full\n");
        return;
    }

    struct Product newProduct;
    strncpy(newProduct.name, name, MAX_NAME_LEN - 1);
    strncpy(newProduct.description, description, MAX_NAME_LEN - 1);
    newProduct.price = price;

    products[numProducts] = newProduct;
    numProducts++;
}

void displayProducts() {
    for (int i = 0; i < numProducts; i++) {
        printf("%s (%s) - $%.2f\n", products[i].name, products[i].description, products[i].price);
    }
}

int main() {
    int choice;

    printf("Product Inventory System\n");
    printf("1. Add product\n");
    printf("2. Display products\n");
    printf("3. Quit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", products[numProducts].name);
                printf("Enter product description: ");
                scanf("%s", products[numProducts].description);
                printf("Enter product price: ");
                scanf("%f", &products[numProducts].price);
                addProduct(products[numProducts].name, products[numProducts].description, products[numProducts].price);
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                fprintf(stderr, "Invalid choice\n");
        }
    }

    return 0;
}