//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void viewProducts();
void updateProduct();
void deleteProduct();
void menu();
char getChoice();

int main() {
    menu();
    return 0;
}

void menu() {
    char choice = getChoice();
    switch (choice) {
        case '1':
            addProduct();
            break;
        case '2':
            viewProducts();
            break;
        case '3':
            updateProduct();
            break;
        case '4':
            deleteProduct();
            break;
        case '5':
            printf("Exiting system.\n");
            return;
        default:
            printf("Invalid choice. Please try again.\n");
            menu();  // recursive call to display menu again
    }
    menu();  // Recursive call to display menu again after an operation
}

char getChoice() {
    char choice;
    printf("\nProduct Inventory System Menu:\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    return choice;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
    } else {
        printf("%-20s %-10s %-10s\n", "Product Name", "Quantity", "Price");
        for (int i = 0; i < productCount; i++) {
            printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void updateProduct() {
    char productName[50];
    printf("Enter the name of the product to update: ");
    scanf("%s", productName);
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Current Quantity: %d, Current Price: %.2f\n", inventory[i].quantity, inventory[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void deleteProduct() {
    char productName[50];
    printf("Enter the name of the product to delete: ");
    scanf("%s", productName);
    
    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            // Shift products to fill the gap
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}