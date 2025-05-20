//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: shocked
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
void displayProducts();
void updateProductQuantity();
void deleteProduct();
void searchProduct();
void menu();
void clearInputBuffer();

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        clearInputBuffer();
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProductQuantity();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("Exiting the inventory system! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}

void menu() {
    printf("\n===================================\n");
    printf("        Product Inventory Menu      \n");
    printf("===================================\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Update Product Quantity\n");
    printf("4. Delete Product\n");
    printf("5. Search Product\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    
    Product p;
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    clearInputBuffer();
    printf("Enter product name: ");
    fgets(p.name, NAME_LENGTH, stdin);
    p.name[strcspn(p.name, "\n")] = 0; // Removing newline character
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    
    inventory[productCount++] = p;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products in inventory!\n");
        return;
    }
    
    printf("\n===================================\n");
    printf("        Product Inventory          \n");
    printf("===================================\n");
    printf("%-10s%-25s%-10s%-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < productCount; i++) {
        printf("%-10d%-25s%-10d%-10.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateProductQuantity() {
    int id, newQuantity;
    printf("Enter product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Current quantity: %d\n", inventory[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Deleting product: %s\n", inventory[i].name);
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            printf("Product found: %s, Quantity: %d, Price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product with ID %d not found!\n", id);
}

void clearInputBuffer() {
    while (getchar() != '\n');
}