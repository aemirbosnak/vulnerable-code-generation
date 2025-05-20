//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 10

typedef struct Product {
    char name[20];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];

void updateInventory(Product *product) {
    printf("Enter the quantity of the product: ");
    scanf("%d", &product->quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &product->price);
}

void displayInventory() {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%s: %d, $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int option;

    printf("Welcome to the C Product Inventory System!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. View Inventory\n");
        printf("2. Update Inventory\n");
        printf("3. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                displayInventory();
                break;
            case 2:
                updateInventory(&products[0]);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}