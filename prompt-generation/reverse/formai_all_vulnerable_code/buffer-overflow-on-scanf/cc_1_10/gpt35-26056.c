//FormAI DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int quantity;
    double price;
};

int main() {
    int num_products;

    // Prompt user to enter the number of products
    printf("Enter the number of products: ");
    scanf("%d", &num_products);

    // Allocate memory for array of product structs
    struct Product *products = (struct Product*)malloc(num_products * sizeof(struct Product));

    // Prompt user to enter details of each product
    for (int i = 0; i < num_products; i++) {
        printf("Enter the details of product %d:\n", i+1);

        // Enter product name
        printf("Name: ");
        scanf("%s", products[i].name);

        // Enter product quantity
        printf("Quantity: ");
        scanf("%d", &products[i].quantity);

        // Enter product price
        printf("Price: ");
        scanf("%lf", &products[i].price);

        printf("\n");
    }

    // Display inventory table
    printf("Inventory:\n");
    printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-10d $%-10.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }

    // Prompt user to search for a product
    char search_name[50];
    printf("\nEnter a product name to search: ");
    scanf("%s", search_name);

    // Search for the product in the array
    for (int i = 0; i < num_products; i++) {
        if (strcmp(search_name, products[i].name) == 0) {
            printf("Product found:\n");
            printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
            printf("%-20s %-10d $%-10.2lf\n", products[i].name, products[i].quantity, products[i].price);
            return 0;
        }
    }

    // If product not found, display error message
    printf("Product not found.\n");

    // Free memory allocation
    free(products);

    return 0;
}