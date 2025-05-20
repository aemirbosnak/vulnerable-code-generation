//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Product;

int main() {
    int num_products, i;
    Product products[MAX_PRODUCTS];
    char filename[MAX_NAME_LEN];

    printf("Enter number of products: ");
    scanf("%d", &num_products);

    printf("Enter product name, quantity, and price for each product:\n");
    for (i = 0; i < num_products; i++) {
        printf("Product %d:\n", i+1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Quantity: ");
        scanf("%d", &products[i].quantity);
        printf("Price: ");
        scanf("%f", &products[i].price);
    }

    printf("Enter filename to save inventory: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file, "Product Inventory\n\n");
    fprintf(file, "Name\tQuantity\tPrice\n");
    for (i = 0; i < num_products; i++) {
        fprintf(file, "%s\t%d\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }

    fclose(file);

    printf("Inventory saved to %s.\n", filename);

    return 0;
}