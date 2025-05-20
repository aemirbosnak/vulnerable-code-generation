//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: rigorous
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

void addProduct();
void viewInventory();
void updateProduct();
void deleteProduct();
void showMenu();

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void showMenu() {
    printf("\n=== Product Inventory System ===\n");
    printf("1. Add Product\n");
    printf("2. View Inventory\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Exit\n");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = productCount + 1; // Simple ID assignment, incrementing.
    
    printf("Enter product name: ");
    scanf(" %[^\n]s", newProduct.name);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount] = newProduct;
    productCount++;
    
    printf("Product added successfully!\n");
}

void viewInventory() {
    if (productCount == 0) {
        printf("No products in inventory!\n");
        return;
    }
    
    printf("\n--- Product Inventory ---\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", 
               inventory[i].id, inventory[i].name, 
               inventory[i].quantity, inventory[i].price);
    }
}

void updateProduct() {
    int id, found = 0;

    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void deleteProduct() {
    int id, found = 0;

    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Deleting product: %s\n", inventory[i].name);
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1]; // Shift products
            }
            productCount--;
            printf("Product deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Product with ID %d not found!\n", id);
    }
}