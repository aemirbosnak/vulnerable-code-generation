//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 200

typedef struct product {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    double price;
} Product;

void read_products(Product products[]) {
    FILE *fp;
    char filename[50] = "products.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d %lf\n", products[count].name, products[count].description, &products[count].quantity, &products[count].price)!= EOF) {
        count++;
    }

    fclose(fp);
}

void display_products(Product products[]) {
    int count = 0;
    while (count < MAX_PRODUCTS && products[count].name[0]!= '\0') {
        printf("\nProduct %d:\n", count + 1);
        printf("Name: %s\n", products[count].name);
        printf("Description: %s\n", products[count].description);
        printf("Quantity: %d\n", products[count].quantity);
        printf("Price: $%.2f\n\n", products[count].price);
        count++;
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    read_products(products);
    display_products(products);

    return 0;
}