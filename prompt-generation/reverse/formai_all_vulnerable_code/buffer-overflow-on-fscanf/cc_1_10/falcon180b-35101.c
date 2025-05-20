//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    int quantity;
    float price;
} Product;

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    char filename[MAX_NAME_LENGTH];
    FILE *file;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read products from file
    while (fscanf(file, "%s %s %s %d %f\n",
                  products[num_products].name,
                  products[num_products].description,
                  products[num_products].category,
                  &products[num_products].quantity,
                  &products[num_products].price) == 5) {
        num_products++;
        if (num_products >= MAX_PRODUCTS) {
            printf("Error: too many products in file.\n");
            fclose(file);
            return 1;
        }
    }

    // Close file
    fclose(file);

    // Display products
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-30s %-20s %5d $%7.2f\n",
               products[i].name,
               products[i].description,
               products[i].category,
               products[i].quantity,
               products[i].price);
    }

    return 0;
}