//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[100];
    int quantity;
    double price;
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(char* name, int quantity, double price) {
    if (numProducts <= MAX_PRODUCTS) {
        Product product;
        strcpy(product.name, name);
        product.quantity = quantity;
        product.price = price;
        inventory[numProducts++] = product;
        printf("Product added successfully!\n");
    } else {
        printf("Cannot add product - inventory is full.\n");
    }
}

void removeProduct(char* name) {
    bool found = false;
    int i = 0;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = true;
            break;
        }
    }

    if (found) {
        for (int j = i; j < numProducts - 1; j++) {
            inventory[j] = inventory[j + 1];
        }
        numProducts--;
        printf("Product removed successfully!\n");
    } else {
        printf("Product not found in inventory.\n");
    }
}

void displayInventory() {
    printf("------------------------------\n");
    printf("|       PRODUCT INVENTORY    |\n");
    printf("------------------------------\n");
    printf("| ID |     Name     | Quantity |   Price  |\n");
    printf("------------------------------\n");
    for (int i = 0; i < numProducts; i++) {
        printf("| %2d | %12s | %8d | $%7.2f |\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("------------------------------\n");
}

int main() {
    int choice = 0;
    char name[100];
    int quantity;
    double price;

    while (choice != 4) {
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%lf", &price);
                addProduct(name, quantity, price);
                break;
            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                removeProduct(name);
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("Thanks for using the Product Inventory System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}