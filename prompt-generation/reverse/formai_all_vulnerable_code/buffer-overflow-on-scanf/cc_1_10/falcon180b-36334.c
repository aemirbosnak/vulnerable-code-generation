//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 200
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} Product;

int main() {
    FILE *fp;
    char filename[MAX_NAME_LEN];
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read products from file
    while (fscanf(fp, "%s %s %s %s\n", products[num_products].name, products[num_products].description, products[num_products].price, products[num_products].quantity)!= EOF) {
        num_products++;
    }

    // Close file
    fclose(fp);

    // Display products
    printf("Product Inventory:\n");
    printf("--------------------------------------------------\n");
    printf("| Name            | Description            | Price | Quantity |\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("| %-50s | %-200s | %-10s | %d |\n", products[i].name, products[i].description, products[i].price, products[i].quantity);
    }
    printf("--------------------------------------------------\n");

    return 0;
}