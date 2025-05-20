//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50
#define PRODUCT_QUANTITY_LENGTH 10

typedef struct {
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

int main(int argc, char **argv) {
    FILE *file;
    Product *products;
    int num_products = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    products = malloc(MAX_PRODUCTS * sizeof(Product));

    if (products == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    while (fscanf(file, "%s %d", products[num_products].name, &products[num_products].quantity) == 2) {
        num_products++;
    }

    fclose(file);

    printf("Product Inventory:\n");

    for (int i = 0; i < num_products; i++) {
        printf("%s: %d\n", products[i].name, products[i].quantity);
    }

    free(products);

    return 0;
}