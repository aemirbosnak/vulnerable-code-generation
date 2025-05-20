//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 200

struct product {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    int quantity;
    float price;
};

int main() {
    int num_products;
    struct product products[MAX_PRODUCTS];
    FILE *inventory_file;
    char filename[50];
    int i;

    // Get number of products from user
    printf("Enter number of products: ");
    scanf("%d", &num_products);

    // Read products from file
    printf("Enter inventory file name: ");
    scanf("%s", filename);
    inventory_file = fopen(filename, "r");

    if (inventory_file == NULL) {
        printf("Error: Unable to open inventory file.\n");
        exit(1);
    }

    for (i = 0; i < num_products && fscanf(inventory_file, "%s %s %d %f\n", products[i].name, products[i].description, &products[i].quantity, &products[i].price) == 4; i++) {
        // Do nothing
    }

    fclose(inventory_file);

    // Print inventory
    printf("\nProduct Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("%s\t%s\t%d\t$%.2f\n", products[i].name, products[i].description, products[i].quantity, products[i].price);
    }

    return 0;
}