//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    char name[50];
    int quantity;
    float price;
} product;

int main() {
    product inventory[MAX_PRODUCTS];
    int num_products = 0;

    // Read products from file
    FILE *fp = fopen("products.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%s %d %f", inventory[num_products].name, &inventory[num_products].quantity, &inventory[num_products].price) != EOF) {
        num_products++;
    }

    fclose(fp);

    // Print inventory
    printf("Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    // Add a new product
    char new_name[50];
    int new_quantity;
    float new_price;

    printf("Enter the name of the new product: ");
    scanf("%s", new_name);

    printf("Enter the quantity of the new product: ");
    scanf("%d", &new_quantity);

    printf("Enter the price of the new product: ");
    scanf("%f", &new_price);

    strcpy(inventory[num_products].name, new_name);
    inventory[num_products].quantity = new_quantity;
    inventory[num_products].price = new_price;
    num_products++;

    // Write products to file
    fp = fopen("products.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_products; i++) {
        fprintf(fp, "%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    fclose(fp);

    return 0;
}