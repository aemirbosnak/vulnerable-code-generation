//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    char description[100];
    int quantity;
    float price;
};

int main() {
    FILE *fp;
    struct Product products[MAX_PRODUCTS];
    int num_products = 0;

    // Load products from file
    fp = fopen("products.txt", "rb");
    if (fp == NULL) {
        printf("Error: cannot open products file.\n");
        return 1;
    }

    while (fread(&products[num_products], sizeof(struct Product), 1, fp) == 1) {
        num_products++;
    }

    fclose(fp);

    // Display product list
    printf("Product List:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %s (%d in stock) - $%.2f\n", i+1, products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    // Add new product
    char new_name[50];
    char new_description[100];
    int new_quantity;
    float new_price;

    printf("\nEnter new product information:\n");
    printf("Name: ");
    scanf("%s", new_name);
    printf("Description: ");
    scanf("%s", new_description);
    printf("Quantity: ");
    scanf("%d", &new_quantity);
    printf("Price: ");
    scanf("%f", &new_price);

    fp = fopen("products.txt", "ab");
    if (fp == NULL) {
        printf("Error: cannot open products file.\n");
        return 1;
    }

    fwrite(&new_name, sizeof(char), 50, fp);
    fwrite(&new_description, sizeof(char), 100, fp);
    fwrite(&new_quantity, sizeof(int), 1, fp);
    fwrite(&new_price, sizeof(float), 1, fp);

    fclose(fp);

    printf("\nNew product added successfully!\n");

    return 0;
}