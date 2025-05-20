//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100

// Structure to hold product information
typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Product;

// Function to compare product names (for sorting)
int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to print product information
void print_product(Product *product) {
    printf("Name: %s\n", product->name);
    printf("Quantity: %d\n", product->quantity);
}

// Main function
int main() {
    // Initialize product array
    Product products[MAX_PRODUCTS];
    memset(products, 0, sizeof(products));

    // Read products from file
    FILE *fp = fopen("products.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open products file.\n");
        return 1;
    }

    int num_products = 0;
    while (fscanf(fp, "%s %d\n", products[num_products].name, &products[num_products].quantity) == 2) {
        num_products++;
        if (num_products == MAX_PRODUCTS) {
            printf("Error: Maximum number of products reached.\n");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    // Sort products by name
    qsort(products, num_products, sizeof(Product), compare_names);

    // Print product inventory
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        print_product(&products[i]);
    }

    return 0;
}