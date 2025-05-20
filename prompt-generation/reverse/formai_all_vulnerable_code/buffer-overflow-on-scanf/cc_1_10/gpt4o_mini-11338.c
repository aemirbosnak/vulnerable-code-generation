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

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    getchar(); // Clear newline character from input buffer
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove newline
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    inventory[productCount++] = newProduct;
    printf("Product added successfully.\n");
}

void updateProduct() {
    int id, i;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Updating product: %s\n", inventory[i].name);
            printf("Enter new product name: ");
            getchar(); // Clear newline character from input buffer
            fgets(inventory[i].name, NAME_LENGTH, stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = 0; // Remove newline
            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully.\n");
            return;
        }
    }
    printf("Product ID not found.\n");
}

void deleteProduct() {
    int id, i;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully.\n");
            return;
        }
    }
    printf("Product ID not found.\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory.\n");
        return;
    }
    
    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, 
            inventory[i].quantity, inventory[i].price);
    }
}

void menu() {
    int choice;
    do {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Display Products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}