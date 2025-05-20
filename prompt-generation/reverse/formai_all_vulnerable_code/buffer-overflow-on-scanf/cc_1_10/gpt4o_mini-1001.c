//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct();
void updateProduct();
void viewProducts();
void deleteProduct();
void showMenu();

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: updateProduct(); break;
            case 3: viewProducts(); break;
            case 4: deleteProduct(); break;
            case 5: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void showMenu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add Product\n");
    printf("2. Update Product\n");
    printf("3. View Products\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount] = newProduct;
    productCount++;
    printf("Product added successfully!\n");
}

void updateProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to update: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in the inventory.\n");
        return;
    }

    printf("\n--- Current Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product Name: %s, Quantity: %d, Price: $%.2f\n",
               inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void deleteProduct() {
    char name[NAME_LENGTH];
    printf("Enter product name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Deleting product: %s\n", inventory[i].name);
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product not found!\n");
}