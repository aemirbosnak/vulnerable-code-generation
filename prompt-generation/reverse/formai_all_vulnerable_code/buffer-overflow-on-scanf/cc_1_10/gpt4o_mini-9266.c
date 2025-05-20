//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define CODE_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int stock;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Cannot add more products. Storage full.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product code: ");
    scanf("%s", newProduct.code);
    printf("Enter stock quantity: ");
    scanf("%d", &newProduct.stock);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    
    products[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
        return;
    }
    
    printf("Product Inventory:\n");
    printf("------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Product Name", "Code", "Stock", "Price");
    printf("------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%-20s %-10s %-10d %-10.2f\n", products[i].name, products[i].code, products[i].stock, products[i].price);
    }
    printf("------------------------------------------------\n");
}

void searchProduct() {
    char code[CODE_LENGTH];
    printf("Enter product code to search: ");
    scanf("%s", code);
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            printf("Product found: \n");
            printf("Name: %s, Code: %s, Stock: %d, Price: %.2f\n", products[i].name, products[i].code, products[i].stock, products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

void updateStock() {
    char code[CODE_LENGTH];
    printf("Enter product code to update stock: ");
    scanf("%s", code);
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].code, code) == 0) {
            int newStock;
            printf("Enter new stock quantity: ");
            scanf("%d", &newStock);
            products[i].stock = newStock;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void displayMenu() {
    printf("Medical Store Management System\n");
    printf("---------------------------------------\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Search for a Product\n");
    printf("4. Update Product Stock\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                updateStock();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    
    return 0;
}