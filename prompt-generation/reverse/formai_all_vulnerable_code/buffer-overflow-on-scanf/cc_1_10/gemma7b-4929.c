//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10

typedef struct Product {
    char name[20];
    int quantity;
    double price;
} Product;

Product products[MAX_PRODUCTS] = {
    {"Panadol", 10, 2.50},
    {"Ibuprofen", 15, 3.00},
    {"Tefagen", 8, 2.20},
    {"Paracetamol", 12, 2.00},
    {"Acetaminophen", 13, 2.75},
    {"Nasocort", 9, 3.50},
    {"Combivent", 11, 3.25},
    {"Vicks Vapor Rub", 14, 2.80},
    {"Betadine", 7, 2.30},
    {"Calamine Lotion", 16, 3.10}
};

int main() {
    int i, choice, quantity, found = 0;
    char name[20];

    printf("Welcome to the C Medical Store Management System!\n");

    // Display product list
    printf("Products:\n");
    for (i = 0; i < MAX_PRODUCTS; i++) {
        printf("%s - %d units, price: %.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }

    // Get product name
    printf("Enter product name: ");
    scanf("%s", name);

    // Search for product
    for (i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(name, products[i].name) == 0) {
            found = 1;
            break;
        }
    }

    // Display product details
    if (found) {
        printf("Product details:\n");
        printf("Name: %s\n", products[i].name);
        printf("Quantity: %d units\n", products[i].quantity);
        printf("Price: %.2lf\n", products[i].price);
    } else {
        printf("Product not found.\n");
    }

    // Get quantity
    if (found) {
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Update product quantity
        products[i].quantity -= quantity;

        // Display updated product list
        printf("Updated product list:\n");
        for (i = 0; i < MAX_PRODUCTS; i++) {
            printf("%s - %d units, price: %.2lf\n", products[i].name, products[i].quantity, products[i].price);
        }
    }

    return 0;
}