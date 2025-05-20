//FormAI DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Product struct
typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

// Global array to hold all products
Product products[MAX_PRODUCTS];

// Global variable to keep track of number of products in the array
int num_products = 0;

// Function to add a product to the inventory
void add_product() {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: inventory is full\n");
        return;
    }

    // Prompt user for product information
    printf("Enter product name: ");
    scanf("%s", products[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[num_products].price);

    printf("Product added successfully\n");
    num_products++;
}

// Function to remove a product from the inventory
void remove_product() {
    if (num_products == 0) {
        printf("Error: inventory is empty\n");
        return;
    }

    // Prompt user for product name
    char name[50];
    printf("Enter product name: ");
    scanf("%s", name);

    // Search for product with matching name
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            // Found matching product, remove it from array
            int j;
            for (j = i; j < num_products - 1; j++) {
                products[j] = products[j+1];
            }
            num_products--;
            printf("Product removed successfully\n");
            return;
        }
    }

    printf("Error: product not found\n");
}

// Function to display all products in the inventory
void display_products() {
    printf("Products in inventory:\n");
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s (%d) - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int option;

    do {
        printf("Product Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                display_products();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 4);

    return 0;
}