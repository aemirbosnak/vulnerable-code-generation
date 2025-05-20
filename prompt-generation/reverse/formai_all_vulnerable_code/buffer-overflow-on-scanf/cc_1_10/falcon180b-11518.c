//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QTY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int qty;
    float price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char filename[MAX_NAME_LENGTH];
    FILE *fp;

    printf("Enter the name of the product inventory file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s %d %f", products[num_products].name, products[num_products].category, products[num_products].description, &products[num_products].qty, &products[num_products].price)!= EOF) {
        num_products++;
        if (num_products >= MAX_PRODUCTS) {
            printf("Error: maximum number of products reached.\n");
            exit(2);
        }
    }

    fclose(fp);

    printf("\nProduct Inventory\n");
    printf("------------------\n");
    printf("Product Name | Category | Description | Quantity | Price\n");
    printf("------------ | -------- | ----------- | -------- | ------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%-50s | %-50s | %s | %d | $%.2f\n", products[i].name, products[i].category, products[i].description, products[i].qty, products[i].price);
    }

    return 0;
}