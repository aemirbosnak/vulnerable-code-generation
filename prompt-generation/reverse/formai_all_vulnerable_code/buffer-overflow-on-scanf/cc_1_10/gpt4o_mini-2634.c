//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define CODE_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    float price;
    int stock;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void displayBanner() {
    printf("========================================\n");
    printf("   CYBER MED STORE MANAGEMENT SYSTEM    \n");
    printf("   Enter the neon-lit realm of health   \n");
    printf("========================================\n");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Storage is full! Cannot add more products\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product code: ");
    scanf("%s", newProduct.code);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product stock: ");
    scanf("%d", &newProduct.stock);

    products[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("No products in the inventory!\n");
        return;
    }

    printf("Available Products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Name: %s, Code: %s, Price: %.2f, Stock: %d\n",
                products[i].name, products[i].code, products[i].price, products[i].stock);
    }
}

void searchProduct() {
    char code[CODE_LENGTH];
    printf("Enter the product code to search: ");
    scanf("%s", code);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            printf("Product Found:\n");
            printf("Name: %s, Code: %s, Price: %.2f, Stock: %d\n",
                    products[i].name, products[i].code, products[i].price, products[i].stock);
            return;
        }
    }

    printf("Product with code %s not found!\n", code);
}

void updateStock() {
    char code[CODE_LENGTH];
    printf("Enter the product code to update stock: ");
    scanf("%s", code);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            printf("Current stock: %d\n", products[i].stock);
            int newStock;
            printf("Enter new stock value: ");
            scanf("%d", &newStock);
            products[i].stock = newStock;
            printf("Stock updated successfully!\n");
            return;
        }
    }

    printf("Product with code %s not found!\n", code);
}

void deleteProduct() {
    char code[CODE_LENGTH];
    printf("Enter the product code to delete: ");
    scanf("%s", code);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }

    printf("Product with code %s not found!\n", code);
}

void showMenu() {
    int choice;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Search Product\n");
        printf("4. Update Stock\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: listProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateStock(); break;
            case 5: deleteProduct(); break;
            case 6: printf("Exiting Cyber Med... Stay safe in the neon night!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
}

int main() {
    displayBanner();
    showMenu();
    return 0;
}