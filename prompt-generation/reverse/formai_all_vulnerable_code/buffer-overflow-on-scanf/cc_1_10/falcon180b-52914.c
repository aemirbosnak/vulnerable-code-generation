//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

// Struct to hold product information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Product;

// Function to compare product names (for sorting)
int compare_names(const void *a, const void *b) {
    const char *name_a = ((const Product *)a)->name;
    const char *name_b = ((const Product *)b)->name;
    return strcmp(name_a, name_b);
}

// Function to compare product prices (for sorting)
int compare_prices(const void *a, const void *b) {
    const Product *product_a = (const Product *)a;
    const Product *product_b = (const Product *)b;
    return (product_a->price > product_b->price) - (product_a->price < product_b->price);
}

int main() {
    // Initialize product inventory
    Product inventory[MAX_PRODUCTS];
    int num_products = 0;

    // Prompt user for number of products to add
    printf("Enter the number of products to add: ");
    scanf("%d", &num_products);

    // Add products to inventory
    for (int i = 0; i < num_products; i++) {
        printf("Enter product %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", inventory[i].name);
        printf("Description: ");
        scanf("%s", inventory[i].description);
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("Price: ");
        scanf("%lf", &inventory[i].price);
    }

    // Sort inventory by name
    qsort(inventory, num_products, sizeof(Product), compare_names);

    // Print sorted inventory
    printf("\nSorted by name:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\n", inventory[i].name);
    }

    // Sort inventory by price
    qsort(inventory, num_products, sizeof(Product), compare_prices);

    // Print sorted inventory
    printf("\nSorted by price:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%.2lf - %s\n", inventory[i].price, inventory[i].name);
    }

    return 0;
}