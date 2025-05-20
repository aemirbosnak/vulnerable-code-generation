//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define CATEGORY_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void deleteProduct();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n=== Product Inventory Management System ===\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    }
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1; // Auto-increment ID
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product category: ");
    scanf("%s", newProduct.category);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount++] = newProduct;
    printf("Product added successfully! ID: %d\n", newProduct.id);
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
        return;
    }
    printf("\n=== Product List ===\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d | Name: %s | Category: %s | Quantity: %d | Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].category,
               inventory[i].quantity, inventory[i].price);
    }
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > productCount) {
        printf("Product not found!\n");
        return;
    }
    
    Product prod = inventory[id - 1];
    printf("Found Product - ID: %d | Name: %s | Category: %s | Quantity: %d | Price: %.2f\n",
           prod.id, prod.name, prod.category, prod.quantity, prod.price);
}

void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Product not found!\n");
        return;
    }

    Product *prod = &inventory[id - 1];
    printf("Updating product: %s\n", prod->name);
    printf("New product name: ");
    scanf("%s", prod->name);
    printf("New product category: ");
    scanf("%s", prod->category);
    printf("New product quantity: ");
    scanf("%d", &prod->quantity);
    printf("New product price: ");
    scanf("%f", &prod->price);

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > productCount) {
        printf("Product not found!\n");
        return;
    }
    
    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}