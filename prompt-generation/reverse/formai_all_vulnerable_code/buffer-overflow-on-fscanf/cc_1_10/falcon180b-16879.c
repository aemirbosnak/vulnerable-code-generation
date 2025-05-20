//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

struct Product {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
};

int main() {
    struct Product products[MAX_PRODUCTS];
    int num_products = 0;
    FILE *fp;

    // Open input file
    fp = fopen("products.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open products.txt\n");
        exit(1);
    }

    // Read products from file
    while (num_products < MAX_PRODUCTS && fscanf(fp, "%s %s %d %lf", products[num_products].name, products[num_products].description, &products[num_products].quantity, &products[num_products].price) == 4) {
        num_products++;
    }

    // Close input file
    fclose(fp);

    // Open output file
    fp = fopen("inventory.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open inventory.txt\n");
        exit(1);
    }

    // Write header
    fprintf(fp, "Product Name\tDescription\tQuantity\tPrice\n");

    // Write inventory
    for (int i = 0; i < num_products; i++) {
        fprintf(fp, "%s\t%s\t%d\t$%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    // Close output file
    fclose(fp);

    return 0;
}