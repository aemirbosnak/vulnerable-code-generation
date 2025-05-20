//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define PRODUCT_NAME_LENGTH 50

typedef struct {
    int id;
    char name[PRODUCT_NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function Prototypes
void addProduct();
void displayProducts();
void updateProduct();
void deleteProduct();
void displayMenu();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the inventory system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Cannot add more products, inventory full.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1; // Simple incremental ID
    printf("Enter product name: ");
    fgets(newProduct.name, PRODUCT_NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline

    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    clearBuffer();

    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    clearBuffer();

    inventory[productCount++] = newProduct;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
        return;
    }

    printf("\n=== Products in Inventory ===\n");
    printf("%-5s %-30s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-5d %-30s %-10d %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    clearBuffer();

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new product name: ");
            fgets(inventory[i].name, PRODUCT_NAME_LENGTH, stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0;

            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            clearBuffer();

            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            clearBuffer();

            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void deleteProduct() {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    clearBuffer();

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Product ID not found.\n");
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // clear the input buffer
}