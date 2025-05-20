//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

void print_products(Product products[], int num_products) {
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s\n", i + 1, products[i].name);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: $%.2f\n\n", products[i].price);
    }
}

void add_product(Product products[], int* num_products) {
    if (*num_products < MAX_PRODUCTS) {
        printf("Enter product name: ");
        scanf("%s", products[*num_products].name);
        printf("Enter product quantity: ");
        scanf("%d", &products[*num_products].quantity);
        printf("Enter product price: ");
        scanf("%f", &products[*num_products].price);
        *num_products += 1;
    } else {
        printf("Maximum number of products reached.\n");
    }
}

void remove_product(Product products[], int* num_products) {
    if (*num_products > 0) {
        printf("Enter product index to remove: ");
        int index;
        scanf("%d", &index);
        if (index >= 0 && index < *num_products) {
            for (int i = index; i < *num_products - 1; i++) {
                products[i] = products[i + 1];
            }
            *num_products -= 1;
        } else {
            printf("Invalid product index.\n");
        }
    } else {
        printf("No products to remove.\n");
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int num_products = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Print products\n");
        printf("4. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                remove_product(products, &num_products);
                break;
            case 3:
                print_products(products, num_products);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}