//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
} Product;

Product* createProduct(const char* name, int quantity) {
    Product* newProduct = malloc(sizeof(Product));
    if (newProduct == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(newProduct->name, name, sizeof(newProduct->name));
    newProduct->quantity = quantity;
    return newProduct;
}

void displayProducts(const Product* products, int numProducts) {
    for (int i = 0; i < numProducts; i++) {
        printf("%s - %d\n", products[i].name, products[i].quantity);
    }
}

int main() {
    Product* products = NULL;
    int numProducts = 0;
    char productName[50];
    int productQuantity;

    while (1) {
        printf("Enter the name of the product (or 'exit' to quit): ");
        scanf("%s", productName);

        if (strcmp(productName, "exit") == 0) {
            break;
        }

        printf("Enter the quantity of %s: ", productName);
        scanf("%d", &productQuantity);

        Product* newProduct = createProduct(productName, productQuantity);
        if (newProduct == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        if (products == NULL) {
            numProducts = 1;
        } else {
            numProducts++;
        }
        products = realloc(products, sizeof(Product) * numProducts);
        if (products == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        memcpy(products + numProducts - 1, newProduct, sizeof(Product));
    }

    displayProducts(products, numProducts);

    free(products);
    return 0;
}