//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50
#define MAX_QTY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int qty;
    float price;
} Product;

void addProduct(Product products[], int size, char name[], int qty, float price) {
    if (size >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add product.\n");
        return;
    }

    strcpy(products[size].name, name);
    products[size].qty = qty;
    products[size].price = price;

    printf("Product added successfully!\n");
}

void displayProducts(Product products[], int size) {
    printf("Product Inventory:\n");

    for (int i = 0; i < size; i++) {
        printf("%d. %s - %d units - $%.2f\n", i+1, products[i].name, products[i].qty, products[i].price);
    }
}

void updateProductQty(Product products[], int size, char name[], int qty) {
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].name, name) == 0) {
            products[i].qty += qty;

            printf("Product quantity updated successfully!\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void main() {
    Product products[MAX_PRODUCTS];
    int size = 0;

    while (1) {
        printf("1. Add Product\n2. Display Products\n3. Update Product Quantity\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN];
                int qty;
                float price;

                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &qty);
                printf("Enter price: ");
                scanf("%f", &price);

                addProduct(products, size, name, qty, price);
                break;
            }

            case 2: {
                displayProducts(products, size);
                break;
            }

            case 3: {
                char name[MAX_NAME_LEN];
                int qty;

                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity to update: ");
                scanf("%d", &qty);

                updateProductQty(products, size, name, qty);
                break;
            }

            case 4: {
                exit(0);
            }

            default: {
                printf("Invalid choice! Please try again.\n");
            }
        }
    }
}