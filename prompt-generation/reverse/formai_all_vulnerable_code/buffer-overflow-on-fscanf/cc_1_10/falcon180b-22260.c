//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_PRICE_LENGTH 10
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char price[MAX_PRICE_LENGTH];
    int quantity;
} Product;

void initialize_product(Product* product) {
    strcpy(product->name, "");
    strcpy(product->description, "");
    strcpy(product->category, "");
    strcpy(product->price, "");
    product->quantity = 0;
}

void print_product(Product* product) {
    printf("Name: %s\n", product->name);
    printf("Description: %s\n", product->description);
    printf("Category: %s\n", product->category);
    printf("Price: $%s\n", product->price);
    printf("Quantity: %d\n", product->quantity);
}

int main() {
    FILE* inventory_file = fopen("inventory.txt", "r");
    if (inventory_file == NULL) {
        printf("Error: Could not open inventory file.\n");
        return 1;
    }

    Product inventory[MAX_PRODUCTS];
    int num_products = 0;

    while (fscanf(inventory_file, "%s %s %s %s %d", inventory[num_products].name, inventory[num_products].description, inventory[num_products].category, inventory[num_products].price, &inventory[num_products].quantity)!= EOF) {
        num_products++;
    }

    fclose(inventory_file);

    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        print_product(&inventory[i]);
    }

    return 0;
}