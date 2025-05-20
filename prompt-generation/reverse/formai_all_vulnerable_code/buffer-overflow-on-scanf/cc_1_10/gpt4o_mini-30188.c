//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Product;

Product warehouse[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Warehouse is full, cannot add more products.\n");
        return;
    }
    Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    warehouse[productCount] = newProduct;
    productCount++;
    printf("Product added successfully.\n");
}

void removeProduct() {
    int id;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        warehouse[i] = warehouse[i + 1];
    }
    productCount--;
    printf("Product removed successfully.\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("No products in the warehouse.\n");
        return;
    }
    printf("Warehouse Products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

void searchProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            printf("Product found - ID: %d, Name: %s, Quantity: %d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. List Products\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                listProducts();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}