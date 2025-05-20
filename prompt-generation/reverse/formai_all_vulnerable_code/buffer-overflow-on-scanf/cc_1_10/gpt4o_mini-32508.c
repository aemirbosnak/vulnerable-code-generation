//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int *productCount);
void viewProducts(const Product products[], int productCount);
void deleteProduct(Product products[], int *productCount);
int findProductIndex(const Product products[], int productCount, int id);
void displayMenu();

int main() {
    Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                viewProducts(products, productCount);
                break;
            case 3:
                deleteProduct(products, &productCount);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Delete Product\n");
    printf("4. Exit\n");
}

void addProduct(Product products[], int *productCount) {
    if (*productCount >= MAX_PRODUCTS) {
        printf("Inventory full. Unable to add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = *productCount + 1; // ID starts from 1
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[*productCount] = newProduct;
    (*productCount)++;
    printf("Product added successfully!\n");
}

void viewProducts(const Product products[], int productCount) {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\n--- Product List ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", 
               products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

void deleteProduct(Product products[], int *productCount) {
    if (*productCount == 0) {
        printf("No products to delete.\n");
        return;
    }
    
    int id;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);
    
    int index = findProductIndex(products, *productCount, id);
    if (index == -1) {
        printf("Product with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < *productCount - 1; i++) {
        products[i] = products[i + 1];
    }
    (*productCount)--;
    printf("Product deleted successfully!\n");
}

int findProductIndex(const Product products[], int productCount, int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    return -1;
}