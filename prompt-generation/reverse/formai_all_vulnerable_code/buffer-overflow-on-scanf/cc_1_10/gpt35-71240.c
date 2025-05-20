//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Product;

int numProducts = 0;
Product products[MAX_PRODUCTS];

void addProduct(char* name, int quantity, float price) {
    if (numProducts < MAX_PRODUCTS) {
        Product product;
        strcpy(product.name, name);
        product.quantity = quantity;
        product.price = price;
        products[numProducts++] = product;
        printf("%s added to the warehouse.\n", name);
    } else {
        printf("Warehouse is full. Cannot add %s.\n", name);
    }
}

void removeProduct(char* name) {
    int i;
    for (i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("%s removed from the warehouse.\n", name);
            products[i] = products[--numProducts];
            return;
        }
    }
    printf("%s not found in the warehouse.\n", name);
}

void listProducts() {
    if (numProducts == 0) {
        printf("Warehouse is empty.\n");
    } else {
        printf("Products in the warehouse:\n");
        int i;
        for (i = 0; i < numProducts; i++) {
            printf("%d. %s (Quantity: %d, Price: $%.2f)\n", i + 1, products[i].name, products[i].quantity, products[i].price);
        }
    }
}

int main() {
    printf("Welcome to the Warehouse Management System!\n");
    printf("============================================\n");

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the name of the product: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                int quantity;
                printf("Enter the quantity of %s: ", name);
                scanf("%d", &quantity);
                float price;
                printf("Enter the price of %s: ", name);
                scanf("%f", &price);
                addProduct(name, quantity, price);
                break;
            case 2:
                printf("\nEnter the name of the product to remove: ");
                char nameToRemove[MAX_NAME_LENGTH];
                scanf("%s", nameToRemove);
                removeProduct(nameToRemove);
                break;
            case 3:
                listProducts();
                break;
            case 4:
                printf("\nExiting the Warehouse Management System...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}