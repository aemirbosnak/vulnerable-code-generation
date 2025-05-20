//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: introspective
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

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1; // Auto-incrementing ID
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    clearInputBuffer();

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void displayInventory() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
        return;
    }

    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *product = &inventory[id - 1];
    printf("Updating %s (ID: %d)\n", product->name, product->id);
    printf("Enter new quantity: ");
    scanf("%d", &product->quantity);
    printf("Enter new price: ");
    scanf("%f", &product->price);
    clearInputBuffer();

    printf("Product updated successfully!\n");
}

void deleteProduct() {
    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift left
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Product Inventory System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    menu();
    return 0;
}