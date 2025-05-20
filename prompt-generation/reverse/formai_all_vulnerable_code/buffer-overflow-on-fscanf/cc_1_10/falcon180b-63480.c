//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_QUANTITY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
} Product;

int main() {
    FILE *fp;
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char filename[50] = "products.txt";

    // Open input file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read in products
    while (fscanf(fp, "%s %s %s %d\n", products[num_products].name, products[num_products].category, products[num_products].description, &products[num_products].quantity)!= EOF) {
        num_products++;
    }

    // Close input file
    fclose(fp);

    // Sort products by name
    for (int i = 0; i < num_products - 1; i++) {
        for (int j = i + 1; j < num_products; j++) {
            if (strcmp(products[i].name, products[j].name) > 0) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }

    // Print products
    printf("Product Name\tCategory\tDescription\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%s\t%s\t%d\n", products[i].name, products[i].category, products[i].description, products[i].quantity);
    }

    // Close program
    return 0;
}