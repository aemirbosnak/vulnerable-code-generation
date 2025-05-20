//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int stock;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void removeProduct();
void viewProducts();
void updateStock(int id, int quantity);
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. View Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                viewProducts();
                break;
            case 4:
                printf("Exiting the system...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Product limit reached! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1;
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline character
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter stock quantity: ");
    scanf("%d", &newProduct.stock);
    clearInputBuffer();

    products[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void removeProduct() {
    int id;
    printf("Enter the product ID to remove: ");
    scanf("%d", &id);
    clearInputBuffer();

    if (id < 1 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        products[i] = products[i + 1];
    }
    productCount--;
    printf("Product removed successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products available.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    printf("ID\tName\t\tPrice\tStock\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}